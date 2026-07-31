const fs = require('fs');
const path = require('path');

const REMARK_TEMPLATE = `<!doctype html>
<html>
  <head>
    <title>{{title}}</title>
    <meta charset="utf-8" />
    <meta
      name="viewport"
      content="user-scalable=no,initial-scale=1,maximum-scale=1,minimum-scale=1,width=device-width"
    />
    <link rel="stylesheet" type="text/css" href="../css/spaces.css" />
    <link rel="stylesheet" type="text/css" href="../css/slides.css" />
    <link rel="stylesheet" type="text/css" href="../css/nord-dark.css" />
    <link rel="stylesheet" type="text/css" href="../css/nord-light.css" />
    <link rel="stylesheet" type="text/css" href="../css/font-nord.css" />
    <link rel="stylesheet" type="text/css" href="../css/bg-nord.css" />
    <link rel="stylesheet" type="text/css" href="../css/style.css" />
    <link rel="stylesheet" type="text/css" href="../katex/katex.min.css" />
  </head>
  <body>
    <script src="../js/remark.min.js"></script>
    <script src="../katex/katex.min.js" type="text/javascript"></script>
    <script src="../katex/contrib/auto-render.min.js" type="text/javascript"></script>
    <script src="../js/mermaid.min.js"></script>
    <script type="text/javascript">
      var renderSlides = function () {
        renderMathInElement(document.body, {
          delimiters: [
            { left: '$$', right: '$$', display: true },
            { left: '$', right: '$', display: false },
          ],
          ignoredTags: ['pre', 'code'],
        });
        mermaid.initialize({ startOnLoad: false, theme: 'forest' });
        var mermaidCmps = document.querySelectorAll('.mermaid');
        for (var i = 0; i < mermaidCmps.length; i++) {
          var cmp = mermaidCmps[i];
          if (cmp.querySelector('svg')) continue;
          var def = '';
          var pre = cmp.querySelector('pre');
          if (pre) { def = pre.textContent; }
          else { def = cmp.textContent.trim(); }
          if (!def) continue;
          (function (el, id, d) {
            el.innerHTML = '';
            mermaid.render(id, d).then(function (r) {
              el.innerHTML = r.svg;
              if (typeof r.bindFunctions === 'function') r.bindFunctions(el);
            }).catch(function () {
              el.innerHTML = '<p style="color:red;text-align:center;">Diagram error</p>';
            });
          })(cmp, 'mmd' + i, def);
        }
      };
      var slideshow = remark.create(
        {
          sourceUrl: 'README.md',
          ratio: '16:10',
          highlightStyle: 'tomorrow-night-blue',
          highlightLines: true,
          countIncrementalSlides: false,
          navigation: {
            scroll: false,
            touch: true,
            click: false,
          },
        },
        renderSlides
      );
    </script>
  </body>
</html>
`;

const SKIP_DIRS = [
  'js',
  'css',
  'katex',
  'mermaid',
  'tongyi',
  '.github',
  '.vscode',
  'bob',
  'static',
  'node_modules',
  'screenshots',
];

const BASE_URL = 'https://luk036.github.io';

function extractTitle(content) {
  const match = content.match(/^#\s+(.+)$/m);
  return match ? match[1].trim() : 'Untitled';
}

function listTopicDirs(rootDir) {
  const entries = fs.readdirSync(rootDir, { withFileTypes: true });
  return entries
    .filter(e => e.isDirectory() && !e.name.startsWith('.') && !SKIP_DIRS.includes(e.name))
    .map(e => e.name)
    .sort();
}

function buildFromReadme(rootDir, dirName) {
  const dirPath = path.join(rootDir, dirName);
  const readmePath = path.join(dirPath, 'README.md');
  const indexPath = path.join(dirPath, 'index.html');

  if (!fs.existsSync(readmePath)) {
    console.log(`  ${dirName}: no README.md, skipping`);
    return false;
  }

  const mdStats = fs.statSync(readmePath);
  let needsBuild = true;

  if (fs.existsSync(indexPath)) {
    const htmlStats = fs.statSync(indexPath);
    needsBuild = mdStats.mtimeMs > htmlStats.mtimeMs;
  }

  if (!needsBuild) {
    console.log(`  ${dirName}: index.html up to date`);
    return false;
  }

  const content = fs.readFileSync(readmePath, 'utf-8');
  const title = extractTitle(content);

  fs.writeFileSync(indexPath, REMARK_TEMPLATE.replace('{{title}}', title));
  console.log(`  ${dirName}: index.html generated`);
  return true;
}

function escapeXml(text) {
  return text.replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;');
}

function generateSitemap(rootDir, topicDirs) {
  const urls = [{ loc: `${BASE_URL}/`, changefreq: 'weekly', priority: '1.0' }];

  for (const dirName of topicDirs) {
    const dirPath = path.join(rootDir, dirName);
    if (!fs.existsSync(path.join(dirPath, 'index.html'))) continue;

    urls.push({ loc: `${BASE_URL}/${dirName}/`, changefreq: 'monthly', priority: '0.8' });

    const files = fs
      .readdirSync(dirPath)
      .filter(f => f.endsWith('.html') && f !== 'index.html')
      .sort();
    for (const file of files) {
      urls.push({
        loc: `${BASE_URL}/${dirName}/${encodeURI(file)}`,
        changefreq: 'monthly',
        priority: '0.5',
      });
    }
  }

  const lines = [
    '<?xml version="1.0" encoding="UTF-8"?>',
    '<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">',
  ];
  for (const url of urls) {
    lines.push('  <url>');
    lines.push(`    <loc>${escapeXml(url.loc)}</loc>`);
    lines.push(`    <changefreq>${url.changefreq}</changefreq>`);
    lines.push(`    <priority>${url.priority}</priority>`);
    lines.push('  </url>');
  }
  lines.push('</urlset>', '');
  return lines.join('\n');
}

function main() {
  const rootDir = process.cwd();
  const topicDirs = listTopicDirs(rootDir);

  console.log('Building HTML from Markdown files...\n');

  let built = 0;
  for (const dirName of topicDirs) {
    if (buildFromReadme(rootDir, dirName)) {
      built++;
    }
  }

  console.log('\nGenerating sitemap.xml...');
  fs.writeFileSync(path.join(rootDir, 'sitemap.xml'), generateSitemap(rootDir, topicDirs));
  console.log('  sitemap.xml generated');

  console.log(`\nDone. Built ${built} HTML files.`);
}

main();
