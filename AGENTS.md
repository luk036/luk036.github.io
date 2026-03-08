# AGENTS.md - Agentic Coding Guidelines

This repository is a static GitHub Pages site hosting educational content (math, algorithms, hardware design, etc.). It contains HTML slides generated from Markdown using remark.js and KaTeX for math.

## Project Overview

- **Type**: Static website (GitHub Pages)
- **Content**: Educational slides in Markdown/HTML with KaTeX math
- **Tech Stack**: remark.js, KaTeX, Mermaid, Prettier

---

## Build, Lint & Format Commands

### Using npm Scripts (Recommended)

```bash
# Format all supported files
npm run format

# Check formatting without writing
npm run format:check

# Optimize SVGs
npm run svgo
```

### Pre-commit Hooks

```bash
# Install pre-commit hooks
pip install pre-commit
pre-commit install

# Run pre-commit manually
npm run precommit
```

### Direct Commands

```bash
# Prettier (formatting)
npx prettier --write .
npx prettier --check .

# Black (Python formatting)
black .

# isort (Python import sorting)
isort .

# Flake8 (Python linting)
flake8 .

# SVGO (SVG optimization)
npx svgo --folder .
```

---

## CI/CD

### GitHub Actions

The project uses GitHub Actions for CI (see `.github/workflows/ci.yml`). It runs on push to main and pull requests, executing:

- Prettier check
- Black formatting check
- isort import check
- Flake8 linting
- pre-commit hooks

---

## Code Style Guidelines

### General Principles

1. **Keep lines reasonably short** (max ~100 chars when practical)
2. **Use LF line endings** (Linux/Mac convention)
3. **No trailing whitespace**
4. **Use blank lines sparingly** to improve readability

### Markdown

- Use ATX-style headers (`#`, `##`, `###`)
- Use fenced code blocks with language identifiers
- Prefer `-` for unordered lists
- Include blank line before and after code blocks

### HTML

- Use semantic HTML5 elements
- Indent with 2 spaces
- Use double quotes for attributes
- Self-closing tags for void elements (`<img />`, `<br />`)

### CSS

- Follow existing style in `style.css`
- Use CSS variables for theming
- Keep selectors simple and specific

### JavaScript

- Use ES6+ syntax (const/let, arrow functions, template literals)
- Use meaningful variable names (camelCase)
- Add semicolons for clarity
- Keep functions small and focused

### Python (examples only)

- Follow Black formatting (max 88 chars per line)
- Use isort for import ordering (stdlib, third-party, local)
- Follow PEP 8 conventions

### Naming Conventions

| Type        | Convention  | Example                         |
| ----------- | ----------- | ------------------------------- |
| Files       | kebab-case  | `my-script.js`, `lecture-01.md` |
| Variables   | camelCase   | `myVariable`, `resultList`      |
| Constants   | UPPER_SNAKE | `MAX_SIZE`, `DEFAULT_TIMEOUT`   |
| CSS Classes | kebab-case  | `.my-class`, `.nav-container`   |

### Error Handling

- Use meaningful error messages
- Log errors appropriately (console.log for JS)
- Don't suppress errors silently

---

## File Organization

```
.
├── index.html          # Main entry point
├── 404.html            # Custom 404 page
├── style.css          # Global styles
├── js/                # Client-side JavaScript
├── css/               # Stylesheets
├── katex/             # Math rendering
├── mermaid/           # Diagrams
├── [topic]/           # Topic directories (cvx/, algo4dfm/, etc.)
│   ├── index.html
│   └── *.md           # Source markdown
├── .github/workflows/ # GitHub Actions CI
└── .vscode/          # VS Code settings
```

---

## Common Tasks

### Adding a New Lecture/Slide

1. Create Markdown file in appropriate topic directory
2. Use remark.js slide format (horizontal rule `---` for slide breaks)
3. Include KaTeX for math: `$...$` inline, `$$...$$` block
4. Run `npm run format` to format
5. Convert to HTML (if needed - some are pre-built)

### Editing Existing Content

1. Edit the source Markdown file
2. Run `npm run format` to format
3. If pre-commit hooks are installed, they'll catch issues

### Adding SVG Graphics

1. Add SVG to relevant directory
2. Run `npx svgo --input yourfile.svg --output yourfile.svg`

---

## Dependencies

- **Prettier 3.2.5** (code formatting)
- **SVGO** (SVG optimization)
- **Pre-commit hooks**: Black, isort, flake8, markdownlint

Installed via npm and pip. See `package.json` and `pip.list`.

---

## Notes for Agents

1. **Don't modify generated HTML** - edit source Markdown instead
2. **Preserve KaTeX math** - don't re-render equations
3. **Test locally** - use a local server to preview changes
4. **Keep changes minimal** - this is a content repository, not a software project
5. **Check file size** - avoid adding large files (warn if >1MB)
6. **Generated HTML files should not be committed** - they are build artifacts
