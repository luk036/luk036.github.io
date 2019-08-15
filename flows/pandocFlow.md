title: Pandoc Flow
class: animation-fade
layout: true

<!-- This slide will serve as the base layout for all your slides -->
.bottom-bar[
  {{title}}
]

---

class: impact

{{title}}
=========

Wai-Shing Luk
-------------

---

Why Markdown?
-------------

-   Easier to write than LaTeX, or Microsoft Word, and PowerPoint.
-   A lot of tool support.
-   Easier grammarly check
-   Convertable to other formats via `pandoc`
-   Github uses Markdown

Why not?
--------

-   Markdown cannot handle complex document.

---

Why Pandoc?
-----------

-   To write final year thesis (fd-bylw)
-   To write journal paper (fdxb)
-   Markdown to latex beamer slides
-   Markdown to epub

---

Install pandoc via Cabal system
-------------------------------

-   In order to install the latest version of pandoc on Linux, you need
    to install the cabal system (because pandoc is written in Haskell).
    You may need to install the missing componnents:
    -   sudo apt install cabal-install libghc-zlib-dev
-   Install the pandoc package:

``` {.terminal}
ubuntu@ubuntu:~$ cabal update
ubuntu@ubuntu:~$ cabal install pandoc
ubuntu@ubuntu:~$ cabal install pandoc-citeproc
ubuntu@ubuntu:~$ cabal install pandoc-crossref
```

The executables are in `~/.cabal/bin` directory

---

Install pandoc via Scoop (on Windows 10)
----------------------------------------

-   In order to install the latest version of pandoc on Windows 10, the
    easiest way is to install the scoop system (and add extra bucket)
-   Install the pandoc package

``` {.powershell}
PS E:\>  scoop bucket add extras
PS E:\>  scoop install pandoc
PS E:\>  scoop install pandoc-crossref
```

---

Install additional filters
--------------------------

-   Install pandocfilters via python pip

``` {.terminal}
ubuntu@ubuntu:~$ sudo apt install python-pip
ubuntu@ubuntu:~$ sudo pip install pandocfilters
```

---

Extensions of Visual Studio Code
--------------------------------

-   Markdown Shortcuts
-   Markdown+Math
-   markdownlint
-   vscode-pandoc

---

class: impact

Q & A?
==========
