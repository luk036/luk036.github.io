title: Markdown + Pandoc + \LaTeX\
class: animation-fade
layout: true

<!-- This slide will serve as the base layout for all your slides -->

.bottom-bar[
{{title}}
]

---

class: impact

# {{title}}

## Wai-Shing Luk

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
  - qtikz

---

## Extensions of Visual Studio Code

- LaTeX Workshop
- LaTeX language support
- Makrdown Preview Enhanced
- makrdownlint
- Pandoc Citer [o]

---

## GTD Markdown

- @context, e.g @fq, @errand, @internet, @hk
- [o] todo
- [x] todo finish
- ( ) add reason
- colorize
  - red: personal
    - orange: love
    - yellow: family
  - green: social
    - cyan: meeting
  - blue: work
    - purple: training

---

## LaTeX Workshop

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
- Go to https://www.ShareLaTeX.com or https://www.overleaf.com.
  - Select the templates of your journal/conference sample files.
  - Download all the .cls, .clo, .tex, and .bib files.

---

## Online References

- [ShareLaTeX](https://www.sharelatex.com)
- [Overleaf](https://www.overleaf.com)
- [Function Support in KaTeX](https://khan.github.io/KaTeX/function-support.html)

---

class: impact

# Q & A 🗣️
