layout: true
class: typo, typo-selection

---

class: nord-dark, center, middle

# Pandoc Flow

@luk036

---

## What is Markdown?

-  Markdown is a markup language created by John Gruber that allows users to write plain text documents with easy-to-understand formatting, which can be easily converted into valid XHTML (or HTML) documents.

-  Markdown absorbs many of the plain text markup features already present in emails, and because of its simplicity, ease of use, and support for images, charts, and mathematical equations, many websites and applications have adopted Markdown to create help documents or for posting messages in forums.

---

## Why Markdown?

-   Lightweight
-   Supports images, charts, math equations
-   Used by many websites and applications for help docs and forums
-   Easy to embed in webpages
-   Useful for version control
-   Large community and ecosystem
-   Convertible to many other formats via `pandoc`

---

## Why not Markdown?

*   Complex Design - Markdown is great for simple text formatting and basic HTML, but if you need to create complex designs or layouts, it may fall short. In these cases, you may want to consider using a more powerful markup language like HTML or LaTeX, or a desktop publishing software like InDesign or QuarkXPress.

*   Formatted Text Editing - Markdown is great for writing plain text documents, but if you need to edit formatted text or create rich text documents with multiple fonts, colors, and styles, you may want to use a word processing application like Microsoft Word or Google Docs.

---

## What is Pandoc?

Pandoc is a **document conversion tool** that allows you to convert files from one format to another. It can handle multiple formats, including Markdown, HTML, LaTeX, PDF, and Word, and convert them into each other as needed. Pandoc is powerful and flexible, and it can be used in various ways to create beautiful and well-formatted documents.

---

## Why Pandoc?

-   To write final year thesis (fd-bylw)
-   To write journal paper (fdxb)
-   Markdown to latex beamer slides
-   Markdown to epub

---

## Install pandoc via Conda

``` terminal
ubuntu@ubuntu:~$ conda install pandoc -c conda-forge
ubuntu@ubuntu:~$ conda install pandoc-crossref -c conda-forge
```

---

## Install pandoc via Scoop (on Windows 10)

-   In order to install the latest version of pandoc on Windows 10, the
    easiest way is to install the scoop system (and add extra bucket)
-   Install the pandoc package

``` powershell
PS E:\>  scoop bucket add extras
PS E:\>  scoop install pandoc
PS E:\>  scoop install pandoc-crossref
```

---

## Install additional filters

-   Install pandocfilters via python pip

``` terminal
ubuntu@ubuntu:~$ sudo apt install python-pip
ubuntu@ubuntu:~$ sudo pip install pandocfilters
```

---

## Extensions of Visual Studio Code

-   Markdown Preview Enhanced
-   markdownlint
-   vscode-pandoc
-   LaTeX Workshop

---

class: nord-dark, center, middle

# Q & A 🙋
