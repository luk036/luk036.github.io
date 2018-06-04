---
title: Beamer Slides using Pandoc and Markdown
author: Wai-Shing Luk
...

## Introduction

### Why Markup Language?

-   Separate "content" with "style".

### Why Pandoc and Beamer?

-   For professional presentation.
-   Tikz diagrams.


## A simple example `intro.md`

```markdown
---
title: Beamer Slides using Pandoc and Markdown
author: Wai-Shing Luk
...

## Introduction

### Why Markup Language?

-   Separate "content" with "style".

### Why Beamer?

-   For professional presentation.
-   Tikz diagrams.

```


---

## A simple header `beamer.yaml`

\scriptsize

```yaml
---
fontsize: 10pt
classoption:
  - serif,onlymath
institute: Fudan University
date: \today
header-includes:
  - \usetheme{default}
  - \usepackage[footnotesize]{subfigure}
  - \usepackage{tikz,pgf,pgfplots}
  - \usetikzlibrary{arrows}
  - \definecolor{qqqqff}{rgb}{0.,0.,1.}
  - \newcommand{\columnsbegin}{\begin{columns}}
  - \newcommand{\columnsend}{\end{columns}}
  - \newcommand{\col}[1]{\column{#1}}
  - \pgfdeclareimage[height=0.5cm]{fudan-logo}{fudan-logo.jpg}
  - \logo{\pgfuseimage{fudan-logo}}
...
```


## Render Mathematical Equations using LaTeX


\columnsbegin

\col{0.5\textwidth}

\scriptsize

```latex

Consider the following problem:

$$\begin{array}{ll}
  \text{minimize}    & f_0(x), \\
  \text{subject to}  & F(x) \succeq 0,
\end{array}$$

- $F(x)$: a matrix-valued function
- $A \succeq 0$ denotes $A$ is
  positive semidefinite.

```

\col{0.5\textwidth}

Consider the following problem:

$$\begin{array}{ll}
  \text{minimize}    & f_0(x), \\
  \text{subject to}  & F(x) \succeq 0,
\end{array}$$

- $F(x)$: a matrix-valued function
- $A \succeq 0$ denotes $A$ is
  positive semidefinite.

\columnsend


## How to make a two-column slide

```markdown

\columnsbegin

\col{0.5\textwidth}

  Left-hand side

\col{0.5\textwidth}

  Right-hand side

\columnsend

```


## Render Diagrams using Tikz

\columnsbegin

\col{0.4\textwidth}
\scriptsize

```latex

\begin{figure}[hp]
\centering
\input{pole2polar.tikz}
\caption{Example of constructing
    the polar of a point}
\end{figure}

```

\col{0.6\textwidth}

\begin{figure}[hp]
\centering
\input{pole2polar.tikz}
\caption{Example of constructing
    the polar of a point}
\end{figure}

\columnsend

## Table

\scriptsize

\columnsbegin

\col{0.5\textwidth}

```markdown

| Costs        |   28nm     |    20nm     |
|--------------|------------|-------------|
| Fab Costs    | 3B         |  4B - 7B    |
| Process R&D  | 1.2B       | 2.1B - 3B   |
| Mask Costs   | 2M - 3M    | 5M - 8M     |
| Design Costs | 50M - 90M  | 120M - 500M |

: Fab, process, mask, and design costs

```

\col{0.5\textwidth}

| Costs        |   28nm     |    20nm     |
|--------------|------------|-------------|
| Fab Costs    | 3B         |  4B - 7B    |
| Process R&D  | 1.2B       | 2.1B - 3B   |
| Mask Costs   | 2M - 3M    | 5M - 8M     |
| Design Costs | 50M - 90M  | 120M - 500M |

: Fab, process, mask, and design costs

\columnsend


## Crossref

## A sample `crossref.yaml`

\scriptsize

```yaml
---
cref: True
chapters: True
chaptersDept: 2
codeBlockCaptions: True
lofTitle: "## List of Figures"
lotTitle: "## List of Tables"
autoSectionLabels: True
figPrefix:
  - "Fig."
eqnPrefix:
  - "Eq."
tblPrefix:
  - "Table"
lstPrefix:
  - "Listing"
secPrefix:
  - "§"
...
```

## References

## Compile

```bash
pandoc -s -t beamer beamer.yaml intro.md -o intro.tex
```