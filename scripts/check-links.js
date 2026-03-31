const fs = require('fs');
const path = require('path');

const KNOWN_ASSETS = [
  'css/',
  'katex/',
  'js/',
  'mermaid/',
  'static/',
  '.css',
  '.js',
  '.json',
  '.svg',
  '.png',
  '.jpg',
  '.jpeg',
  '.gif',
  '.webp',
  '.woff',
  '.woff2',
  '.eot',
  '.ttf',
  '.ico',
];

const CODE_PATTERNS = [
  /^int\s+/,
  /^void\s+/,
  /^const\s+/,
  /^bool\s+/,
  /^double\s+/,
  /^float\s+/,
  /^Item&/,
  /^Item\*/,
  /^const\s+Item/,
  /^[A-Z][a-zA-Z]*(&|\*)?$/,
  /^\([^)]*\)\s*=>/,
  /^function\s+/,
  /^\$\w+$/,
  /^<\w+/,
  /^&[a-z]/,
  /^&&/,
];

function isAssetLink(href) {
  return KNOWN_ASSETS.some(ext => href.includes(ext));
}

function isCodePattern(href) {
  return CODE_PATTERNS.some(pat => pat.test(href));
}

function checkInternalLinks(rootDir) {
  const errors = [];

  const htmlFiles = [];
  function walk(dir) {
    const entries = fs.readdirSync(dir, { withFileTypes: true });
    for (const entry of entries) {
      const fullPath = path.join(dir, entry.name);
      if (entry.isDirectory()) {
        if (!entry.name.startsWith('.') && entry.name !== 'node_modules') {
          walk(fullPath);
        }
      } else if (entry.name.endsWith('.html')) {
        htmlFiles.push(fullPath);
      }
    }
  }
  walk(rootDir);

  const availableFiles = new Set(htmlFiles.map(f => path.relative(rootDir, f).replace(/\\/g, '/')));

  for (const filePath of htmlFiles) {
    const content = fs.readFileSync(filePath, 'utf-8');
    const relPath = path.relative(rootDir, filePath).replace(/\\/g, '/');
    const dir = path.dirname(relPath);

    const mdLinkRegex = /\[([^\]]+)\]\(([^)]+)\)/g;
    let match;
    while ((match = mdLinkRegex.exec(content)) !== null) {
      const href = match[2];
      if (!href || href.startsWith('http') || href.startsWith('#')) continue;
      if (isAssetLink(href)) continue;
      if (isCodePattern(href)) continue;

      let targetPath;
      if (href.startsWith('/')) {
        targetPath = href.slice(1);
      } else {
        targetPath = path.join(dir, href).replace(/\\/g, '/');
      }

      const normalized = targetPath.replace(/\.md$/, '');
      if (
        !availableFiles.has(targetPath) &&
        !availableFiles.has(targetPath + '.html') &&
        !availableFiles.has(normalized)
      ) {
        errors.push({ file: relPath, link: href, target: targetPath });
      }
    }

    const htmlLinkRegex = /href=["']([^"']+)["']/g;
    while ((match = htmlLinkRegex.exec(content)) !== null) {
      const href = match[1];
      if (href.startsWith('http') || href.startsWith('#') || href.startsWith('javascript:'))
        continue;
      if (isAssetLink(href)) continue;
      if (isCodePattern(href)) continue;

      let targetPath;
      if (href.startsWith('/')) {
        targetPath = href.slice(1);
      } else {
        targetPath = path.join(dir, href).replace(/\\/g, '/');
      }

      const normalized = targetPath.replace(/\.md$/, '');
      if (
        !availableFiles.has(targetPath) &&
        !availableFiles.has(targetPath + '.html') &&
        !availableFiles.has(normalized)
      ) {
        errors.push({ file: relPath, link: href, target: targetPath });
      }
    }
  }

  return errors;
}

function main() {
  const rootDir = process.cwd();

  console.log('Checking internal HTML links...\n');

  const internalErrors = checkInternalLinks(rootDir);

  if (internalErrors.length > 0) {
    console.log('Internal link errors:');
    for (const err of internalErrors.slice(0, 20)) {
      console.log(`  ${err.file}: ${err.link} -> ${err.target} (not found)`);
    }
    if (internalErrors.length > 20) {
      console.log(`  ... and ${internalErrors.length - 20} more`);
    }
  } else {
    console.log('  All internal links OK');
  }

  console.log(`\nFound ${internalErrors.length} internal link error(s).`);

  process.exit(internalErrors.length > 0 ? 1 : 0);
}

main();
