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
    <link rel="stylesheet" type="text/css" href="./css/typo.css" />
    <link rel="stylesheet" type="text/css" href="./css/nord-dark.css" />
    <link rel="stylesheet" type="text/css" href="./css/nord-light.css" />
    <link rel="stylesheet" type="text/css" href="./css/font-nord.css" />
    <link rel="stylesheet" type="text/css" href="./css/bg-nord.css" />
    <script>
      function create() {
        return remark.create({
          sourceUrl: "README.md",
          ratio: "4:3",
        });
      }
    </script>
  </head>
  <body onload="slideshow = create()">
    <script src="js/remark.min.js"></script>
  </body>
</html>
`;

const SKIP_DIRS = ['js', 'css', 'katex', 'mermaid', 'tongyi', '.github', '.vscode', 'bob'];

function extractTitle(content) {
  const match = content.match(/^#\s+(.+)$/m);
  return match ? match[1].trim() : 'Untitled';
}

function buildFromReadme(dirPath) {
  const readmePath = path.join(dirPath, 'README.md');
  const indexPath = path.join(dirPath, 'index.html');

  if (!fs.existsSync(readmePath)) {
    console.log(`  No README.md found in ${path.basename(dirPath)}`);
    return false;
  }

  const mdStats = fs.statSync(readmePath);
  let needsBuild = true;

  if (fs.existsSync(indexPath)) {
    const htmlStats = fs.statSync(indexPath);
    needsBuild = mdStats.mtimeMs > htmlStats.mtimeMs;
  }

  if (!needsBuild) {
    console.log(`  ${path.basename(dirPath)}: index.html up to date`);
    return true;
  }

  const content = fs.readFileSync(readmePath, 'utf-8');
  const title = extractTitle(content);

  const html = REMARK_TEMPLATE.replace('{{title}}', title);

  fs.writeFileSync(indexPath, html);
  console.log(`  ${path.basename(dirPath)}: index.html generated`);
  return true;
}

function main() {
  const rootDir = process.cwd();
  const entries = fs.readdirSync(rootDir, { withFileTypes: true });

  const dirs = entries
    .filter(e => e.isDirectory() && !SKIP_DIRS.includes(e.name))
    .map(e => path.join(rootDir, e.name));

  console.log('Building HTML from Markdown files...\n');

  let built = 0;
  for (const dir of dirs) {
    if (buildFromReadme(dir)) {
      built++;
    }
  }

  console.log(`\nDone. Built ${built} HTML files.`);
}

main();
