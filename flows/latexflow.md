layout: true
class: typo, typo-selection

---

class: nord-dark, center, middle

# LaTeX Flow

@luk036 👨🏻‍🏫

---

# Why?

- Paper submission and publication

---

## Setting Up LaTeX Enviroment in Lubuntu

- sudo apt install:
  - texlive texlive-science
  - texlive-latex-extra (for biblatex)
  - latexmk chktex (for vcode)
  - latexdiff (good for paper revision process)
  - ktikz

---

## 🧩 Extensions of Visual Studio Code

- LaTeX Workshop (turn on chkTeX). In Windows, configure:

```json
"latex-workshop.latex.toolchain": [
  {
    "command": "texify",
    "args": [
        "--src",
        "--pdf",
        "--tex-option=\"-synctex=1\"",
        "--tex-option=\"-interaction=nonstopmode\"",
        "--tex-option=\"-file-line-error\"",
        "%DOC%.tex"
    ]
  }
]
```

---

## How to get started?

- First, determine which journal/conference you want to submit.
- Go to <https://www.overleaf.com>.
  - Select the templates of your journal/conference sample files.
  - Download all the .cls, .clo, .tex, and .bib files.

---

## Online References

- [Overleaf](https://www.overleaf.com)
- [Function Support in KaTeX](https://khan.github.io/KaTeX/function-support.html)

---

class: nord-dark, center, middle

# Q & A 🎤
