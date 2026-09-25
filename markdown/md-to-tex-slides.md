---
title: From Markdown to TeX
subtitle: A Pandoc paper pipeline — and the traps that break it
author: Wai-Shing Luk
institute: Fudan University
date: \today
---

# Agenda

## 📋 Agenda

:::: {.columns}
::: {.column width="47%"}

**🔧 Part 1 — The Pipeline**
Why Markdown, not raw TeX? · pandoc + crossref + citeproc · anatomy of a source

**⚙️ Part 2 — The Build**
the command, flag by flag · one entry point: `make`

:::
::: {.column width="47%"}

**🐛 Part 3 — War Stories**
emoji & Unicode · SVG figures · headings & cleveref · offline citations

**🎯 Part 4 — Takeaways**
a reproducibility checklist

:::
::::

# The Pipeline

## 🤔 Why Write Markdown, Not Raw TeX?

:::: {.columns}
::: {.column width="47%"}

**Markdown wins ✅**

- Readable plain text 📖
- Diffs are *semantic*, not macro noise 🔍
- Math stays LaTeX 📐
- One source → PDF, HTML, slides 🎯

:::
::: {.column width="47%"}

**But TeX wins at 🏆**

- Precise typesetting 📕
- Journal classes 🏛️
- Cross-refs, citations, floats 🔢

:::
::::

> **pandoc** is the bridge: Markdown **in**, TeX **out**, then a real engine compiles it. 🌉

## 🏭 The Toolchain

```{=latex}
\begin{center}
\begin{tikzpicture}[node distance=9mm and 11mm]
  \node[nblue] (md) {📝 Markdown\\+ YAML};
  \node[nyellow, right=of md] (p) {pandoc};
  \node[npurple, right=of p] (cp) {citeproc};
  \node[nyellow, right=of cp] (x) {crossref};
  \node[npink, below=8mm of x] (t) {📜 TeX};
  \node[ngreen, left=of t] (e) {engine};
  \node[ngreen, left=of e] (pdf) {📕 PDF};
  \node[nblue, above=6mm of p, font=\tiny] (y) {🗂️ latex.yaml};
  \node[npurple, above=6mm of cp, font=\tiny] (b) {📚 *.bib · 🎨 *.csl};
  \draw[ar] (md) -- (p);
  \draw[ar] (p) -- (cp);
  \draw[ar] (cp) -- (x);
  \draw[ar] (x) -- (t);
  \draw[ar] (t) -- (e);
  \draw[ar] (e) -- (pdf);
  \draw[ar] (y) -- (p);
  \draw[ar] (b) -- (cp);
\end{tikzpicture}
\end{center}
```

- **citeproc** resolves citations with a `*.bib` database and a `*.csl` style 📚
- **pandoc-crossref** resolves labelled headings, figures and equations 🏷️

## 🧬 Anatomy of a Pandoc-Markdown Paper

Everything is plain text — yet each `@`-thing is **load-bearing**:

| syntax | meaning |
|:--|:--|
| YAML front matter | metadata: title, author, bibliography 🗂️ |
| `## H {#sec:foo}` | a labelled heading 🏷️ |
| `@sec:foo` | cross-reference → “§ 2” 🔗 |
| `[@BGT81]` | citation → “[1]” 📚 |
| math delimiters | inline & display math 📐 |
| `![alt](fig.svg)` | a figure 🖼️ |

> ⚠️ A typo in any of these becomes a `??`, a missing reference, or a hard build error.

## 🗂️ YAML Front Matter = Document Metadata

```yaml
title: "Ellipsoid Method and the Amazing Oracles"
bibliography: ["ellipsoid.bib", "fir-ref.bib"]
csl: "applied-mathematics-letters.csl"
abstract: |
  The ellipsoid method is a powerful optimization technique ...
```

- `title` / `author` → `\title` / `\author` 📕
- `bibliography` → which BibTeX files to search 📚
- `csl` → the **citation style** 🎨
- extra YAML files add **class options**: `latex.yaml`, `crossref.yaml` ⚙️

> Metadata is passed as **positional inputs** *before* the `.md`. 🧩

## 📚 Citations: From `[@key]` to `[1]`

```{=latex}
\begin{center}
\begin{tikzpicture}[node distance=10mm and 14mm]
  \node[nblue] (k) {citation\\in source};
  \node[npurple, right=of k] (cp) {citeproc};
  \node[npurple, above=7mm of cp] (db) {📚 ellipsoid.bib};
  \node[npurple, below=7mm of cp] (csl) {🎨 applied-math.csl};
  \node[ngreen, right=of cp] (n) {[1]\\citation};
  \node[ngreen, below=8mm of n] (ref) {📖 References\\auto-generated};
  \draw[ar] (k) -- (cp);
  \draw[ar] (db) -- (cp);
  \draw[ar] (csl) -- (cp);
  \draw[ar] (cp) -- (n);
  \draw[ar] (cp) |- (ref);
\end{tikzpicture}
\end{center}
```

- `[@key]` parenthetical · `@key` narrative · `[@a; @b]` multiple ✍️
- Cite only keys in a **listed** `.bib` — otherwise the reference silently vanishes 🕳️

## 🔗 Cross-References: From `@sec:label` to “§ 2”

```{=latex}
\begin{center}
\begin{tikzpicture}[node distance=12mm and 20mm]
  \node[nblue] (l) {labelled heading\\\texttt{\{\#sec:cutting\_plane\}}};
  \node[nblue, below=12mm of l] (r) {reference\\\texttt{see @sec:cutting\_plane}};
  \node[nyellow, right=28mm of l] (x) {pandoc-crossref};
  \node[ngreen, right=of x] (out) {see § 2};
  \draw[ar] (l) -- (x);
  \draw[ar] (r) -- (x);
  \draw[ar] (x) -- (out);
\end{tikzpicture}
\end{center}
```

- label prefixes: `sec` · `fig` · `eq` · `tbl` · `lst` 🏷️
- **the separator is file-specific** ⚠️ — `ell-review.md` uses `_`, `ell-review2.md` uses `-`
- a mismatched separator **silently breaks** the link → `??` 🕳️

## 📐 Math: LaTeX Syntax, Rendered Twice

Markdown math **is** LaTeX — pandoc passes it through, and the web renders it with KaTeX:

$$
\mathcal{E}(x_c, P) \;=\; \{\, x \mid (x - {\color{nordblue}x_c})^{\top}
  {\color{nordred}P}^{-1} (x - {\color{nordblue}x_c}) \le 1 \,\}
$$

- in the **PDF** → real TeX, typeset by the LaTeX engine 📕
- in the **HTML** → KaTeX, rendered in the browser 📐

> ⚠️ Keep math **inside math delimiters**. Bare Unicode ($\tau$, $x^2$) in running text is what breaks `pdflatex`.

# The Build

## 🛠️ The Command, Flag by Flag

```bash
pandoc -F pandoc-crossref --citeproc -s -t latex -N --reference-links \
  --shift-heading-level-by=-1 \
  --csl=applied-mathematics-letters.csl \
  ell-review.yaml latex.yaml crossref.yaml ell-review.md -o ell-review.pdf
```

| flag | what it does |
|:--|:--|
| `-F pandoc-crossref` | resolve heading / figure / equation labels 🏷️ |
| `--citeproc` | process citations + build References 📚 |
| `-s -t latex` | standalone LaTeX 📜 |
| `--shift-heading-level-by=-1` | `##` → `\section` 🪜 |
| `--csl=...` | pick the citation style 🎨 |

## 🧩 `pandoc-crossref`: `cref`, or plain `ref`?

```{=latex}
\begin{center}
\begin{tikzpicture}[node distance=10mm and 14mm]
  \node[npurple] (cfg) {\texttt{crossref.yaml}\\\texttt{cref} option};
  \node[nblue, above right=6mm and 20mm of cfg] (tt) {\texttt{true} → cleveref};
  \node[nyellow, below right=6mm and 20mm of cfg] (ff) {\texttt{false} → ref + §};
  \node[nred, right=of tt] (bad) {siamltex class: \texttt{??} ❌};
  \node[ngreen, right=of ff] (good) {always works ✅};
  \draw[ar] (cfg) -- (tt);
  \draw[ar] (cfg) -- (ff);
  \draw[ar] (tt) -- (bad);
  \draw[ar] (ff) -- (good);
\end{tikzpicture}
\end{center}
```

> Our policy: **`cref: false`** — a plain reference plus a literal **§** prefix. No cleveref, no `??`. 🎯

# War Stories

## ☠️ War Story 1: Emoji & Unicode Break `pdflatex`

- one emoji 🪜 → `! Unicode character (U+1FA9C) not set up for use with LaTeX` ❌
- but also **bare Unicode math** in running text: $x^2$, $\le$, $\tau$, $\beta_1$, $\to$ ☠️

$$
\text{broken: } \; x^2/4 \qquad \text{good: } \; {\color{nordgreen}\tfrac{x^2}{4} + y^2 \le 1}
$$

```{=latex}
\begin{center}
\begin{tikzpicture}[node distance=14mm and 24mm]
  \node[nred] (e) {emoji \& bare Unicode};
  \node[nred, right=of e] (err) {\texttt{pdflatex}: Unicode not set up};
  \node[nyellow, below=10mm of e] (fix) {wrap math in delimiters};
  \node[ngreen, right=of fix] (ok) {builds ✅};
  \draw[ar] (e) -- (err);
  \draw[ar] (fix) -- (ok);
\end{tikzpicture}
\end{center}
```

## 🐛 War Story 2: `\argmax` Is Not a Command

- the source wrote `\argmax` — but neither LaTeX nor KaTeX defines it ❌
- result: `! Undefined control sequence` — the build stops 🛑

The fix is a *real* operator 🪄

$$
q_{\max} \;=\; {\color{nordgreen}\operatorname*{arg\,max}_{q \in \mathcal{Q}}}\; f_0(x_0, q)
$$

- `\operatorname*{arg\,max}` needs `amsmath` — pandoc already loads it ✅
- the **same bug** hid in the slide source — fix once, fix everywhere 🔁

## 🪜 War Story 3: Heading Levels → `\section`

A formatter demoted `#` → `##`; pandoc then emitted **no** `\section` at all.

```{=latex}
\begin{center}
\begin{tikzpicture}[node distance=12mm and 26mm]
  \node[ngreen] (h1) {level-1 heading};
  \node[ngreen, right=of h1] (s) {\texttt{section}\\numbering 1, 2 ✅};
  \node[nred, below=10mm of h1] (h2) {level-2 heading};
  \node[nred, right=of h2] (ss) {\texttt{subsection}\\numbering 0.1, 0.2 😱};
  \draw[ar] (h1) -- (s);
  \draw[ar] (h2) -- (ss);
\end{tikzpicture}
\end{center}
```

- before: body headings at `#` → `\section` → “**1. Introduction**” ✅
- after the demotion: every heading became `\subsection` → “**0.1 Introduction**” 😱
- fix **without touching the prose**: `--shift-heading-level-by=-1` 🪄

## 🖼️ War Story 4: SVG Figures Need a Converter

```{=latex}
\begin{center}
\begin{tikzpicture}[node distance=10mm and 16mm]
  \node[nblue] (img) {figure link\\to \texttt{*.svg}};
  \node[nyellow, right=of img] (p) {pandoc → LaTeX};
  \node[ngreen, above right=4mm and 14mm of p] (pdf) {\texttt{svg} → \texttt{pdf}\\\texttt{\textbackslash includegraphics} ✅};
  \node[ngreen, below right=4mm and 14mm of p] (twin) {use the \texttt{*.pdf}\\\texttt{twin} ✅};
  \node[nred, right=14mm of p] (svg) {\texttt{svg} pkg + InkScape\\+ shell-escape ❌};
  \draw[ar] (img) -- (p);
  \draw[ar] (p) -- (pdf);
  \draw[ar] (p) -- (twin);
  \draw[ar] (p) -- (svg);
\end{tikzpicture}
\end{center}
```

- `pdflatex` cannot read `.svg` — pandoc wants **`rsvg-convert`** (librsvg) 🏭
- missing it → the LaTeX `svg` package → needs **InkScape + `--shell-escape`** ❌
- our shortcut: reference the **`.pdf` twin** already shipped beside every `.svg` 🎯

## 😱 War Story 5: `rsvg-convert` Drops Text

Without a fontconfig, `rsvg-convert` renders **no text at all** — geometry only.

![A typical FIR filter structure](md-to-tex-slides.figures/fir_strctr.pdf){height=52%}

- a converted figure can lose every label (`h[0]`, `x[t-1]`, `y[t]`) 🏷️
- a picture can look “present” yet be **informationally empty** 🕳️

## 🧩 War Story 6: cleveref vs `siamltex.cls`

```{=latex}
\begin{center}
\begin{tikzpicture}[node distance=11mm and 14mm]
  \node[nblue] (cl) {cleveref hooks the\\label / counter machinery};
  \node[nred, right=of cl] (m) {\texttt{siamltex.cls}\\redefines them};
  \node[nred, right=of m] (e) {label type empty\\→ every ref is \texttt{??} ❌};
  \node[nyellow, below=10mm of cl] (fix) {\texttt{cref = false}\\§ + plain reference};
  \node[ngreen, right=16mm of fix] (ok) {§ 2, § 3.1 ✅};
  \draw[ar] (cl) -- (m);
  \draw[ar] (m) -- (e);
  \draw[ar] (fix) -- (ok);
\end{tikzpicture}
\end{center}
```

- proven with a **minimal test**: `article` + cleveref → fine; `siamltex` + cleveref → `??` 🔬
- **latest pandoc** does not help — it is the **class**, not the version 📌

## 📴 War Story 7: Citations That Phone Home

```{=latex}
\begin{center}
\begin{tikzpicture}[node distance=9mm and 12mm]
  \node[nblue] (a) {\texttt{*.csl}\\dependent style};
  \node[nblue, right=of a] (b) {\texttt{independent-parent}\\= elsevier-with-titles};
  \node[nred, right=of b] (net) {🌐 fetch from\\zotero.org};
  \node[nred, right=of net] (fail) {ConnectionTimeout ❌};
  \node[nyellow, below=11mm of a] (inline) {inline the parent};
  \node[ngreen, right=of inline] (self) {self-contained ✅\\offline};
  \draw[ar] (a) -- (b);
  \draw[ar] (b) -- (net);
  \draw[ar] (net) -- (fail);
  \draw[ar] (inline) -- (self);
\end{tikzpicture}
\end{center}
```

- that CSL file was only a **stub** — its citation / bibliography logic lived in a parent 🧩
- every fresh machine / CI fetches it → flaky and **non-reproducible** 🎲
- fix: **vendor the parent** → `--citeproc` works **offline** (verified with a dead proxy) 🔒

# Engineering the Build

## ⚙️ One Entry Point: the `Makefile`

| target | produces |
|:--|:--|
| `make paper` | `ell-review.pdf` 📕 |
| `make html` | `ell-review.html` (needs `katex/`) 🌐 |
| `make slides` | `cutting_plane.pdf`, `ell.pdf` (xelatex) 🖥️ |
| `make clean` | remove `temp.*` and aux files 🧹 |

```make
paper: ell-review.pdf

ell-review.pdf: ell-review.md
	pandoc -F pandoc-crossref --citeproc -s -t latex -N \
	  --reference-links --shift-heading-level-by=-1 \
	  ell-review.yaml latex.yaml crossref.yaml ell-review.md -o $@
```

> The `Makefile` records the **flags *and* the reasons** — no more tribal knowledge. 📌

## 🪟 Make on Windows: Two Gotchas

:::: {.columns}
::: {.column width="47%"}

**1. Recipes are exec'd directly** 🐚

- a *simple* recipe runs **without a shell**
- `rm` is not an `.exe` here → `CreateProcess failed` ❌
- force a shell with a metacharacter ✅

```make
clean:
	-@rm -f temp.tex temp.pdf ; true
```

:::
::: {.column width="47%"}

**2. Line endings** 📏

- LF in the repo, CRLF on disk
- keeps diffs **logical**, not whole-file 🔍

**3. Version-matched tools** ⚖️

- `pandoc` and `pandoc-crossref` must agree
- a mismatch warns and can misbehave silently 🎭

:::
::::

## 🧹 Repo Hygiene

- **editor backups** (`*~`, `*.un~`) — untrack and `.gitignore` them 🗑️
- **stale outputs** (`ell-review.tex`, `main-diff.*`) — generated, not source 📜
- **one self-contained CSL** — no network at build time 📴
- **one linter, one config** — two disagreeing linters equal *zero* linters 🎭
- **refresh the agent guide** — write the *why* while it is fresh 🧠

```{=latex}
\begin{center}
\begin{tikzpicture}[node distance=14mm and 26mm]
  \node[nblue] (a) {commit sources only};
  \node[nyellow, right=of a] (b) {artifacts generated,\\never hand-edited};
  \node[ngreen, right=of b] (c) {reproducible:\\any machine, offline ✅};
  \draw[ar] (a) -- (b);
  \draw[ar] (b) -- (c);
\end{tikzpicture}
\end{center}
```

## 🔍 Verify the Artifact, Not the Exit Code

```bash
make paper                                 # exit 0 is necessary, not sufficient
pdfinfo ell-review.pdf                     # page count
pdftotext ell-review.pdf - | grep -c '??'  # unresolved references
```

- `??` count → did the cross-references resolve? 🔗
- extracted text → are the **figure labels** present? (catches dropped SVG text) 🏷️
- page count → did the build actually **change** anything? 📄
- a tiny **CI job** running `make paper` would have caught the stale PDF 🚨

## ✅ Reproducibility Checklist

:::: {.columns}
::: {.column width="47%"}

**Dependencies** 📦

- pandoc **and** pandoc-crossref, version-matched ⚖️
- a LaTeX engine (`pdflatex` / `xelatex`) 📐
- an SVG converter **or** committed PDF twins 🖼️

:::
::: {.column width="47%"}

**Sources** 📝

- a self-contained CSL (offline) 📴
- ASCII math, no emoji (or xelatex) 🔤
- exactly one crossref policy ⚙️

:::
::::

```{=latex}
\begin{center}
\begin{tikzpicture}[node distance=14mm and 26mm]
  \node[nblue] (a) {same inputs};
  \node[nyellow, right=of a] (b) {same command};
  \node[ngreen, right=of b] (c) {same output ✅};
  \draw[ar] (a) -- (b);
  \draw[ar] (b) -- (c);
\end{tikzpicture}
\end{center}
```

## 🎯 Key Takeaways

:::: {.columns}
::: {.column width="47%"}

**The pipeline** 🏭

- pandoc + crossref + citeproc turns Markdown into journal-ready TeX 📕
- one `make` target beats a notebook of shell history 📓

**The habit** 🧠

- inspect the **artifact**, not the exit code 🔍
- vendor **everything** remote — a build must work offline 📴

:::
::: {.column width="47%"}

**The traps** 🪤

- non-ASCII (emoji, bare Unicode) kills `pdflatex` ☠️
- old classes can break cleveref → every reference becomes `??` 🧩
- “standard-looking” macros may not exist (`\argmax`) 🐛

:::
::::

## 📚 References & Further Reading

- **pandoc** — the user's guide & MANUAL: <https://pandoc.org/MANUAL.html> 📖
- **pandoc-crossref** — labels for sections, figures, equations 🔗
- **CSL — Citation Style Language**: <https://citationstyles.org> 🎨
- **cleveref** — and why older document classes can fight it 🧩
- the paper: **“Ellipsoid Method and the Amazing Oracles”** 📕

> Assembled for the `ellipsoid-method` repo; the full checklist lives in **issue #4**. 🗂️

## 🙋 Q&A

**From Markdown to TeX — A Pandoc Paper Pipeline**

Questions? Discussion? 💬

## 👏 Thank You

Same input, same command, same output. 🎯

Slides built with Beamer · TikZ 🧩 · LuaLaTeX 📐 · Nord 🌙
