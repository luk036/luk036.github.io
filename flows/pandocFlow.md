layout: true
class: typo, typo-selection

---

class: nord-dark, center, middle

# Pandoc Flow

@luk036 👨‍💻

---

## Why Markdown?

- Easier to write than LaTeX, or Microsoft Word, and PowerPoint.
- A lot of tool support.
- Easier Grammarly check
- Convertible to other formats via `pandoc`
- GitHub 🐙 uses Markdown

## Why not?

- Markdown cannot handle complex document.

---

## Why Pandoc?

- To write final year thesis (fd-bylw)
- To write journal paper (fdxb)
- Markdown to latex beamer slides
- Markdown to epub

---

## Install pandoc via Conda

```terminal
ubuntu@ubuntu:~$ conda install pandoc -c conda-forge
ubuntu@ubuntu:~$ conda install pandoc-crossref -c conda-forge
```

---

## Install pandoc via Scoop (on Windows 10)

- In order to install the latest version of pandoc on Windows 10, the
  easiest way is to install the scoop system (and add extra bucket)
- Install the pandoc package

```powershell
PS E:\>  scoop bucket add extras
PS E:\>  scoop install pandoc
PS E:\>  scoop install pandoc-crossref
```

---

## Install additional filters

- Install pandocfilters via python pip

```terminal
ubuntu@ubuntu:~$ sudo apt install python-pip
ubuntu@ubuntu:~$ sudo pip install pandocfilters
```

---

## 🧩 Extensions of Visual Studio Code

- Markdown Preview Enhanced
- markdownlint
- vscode-pandoc
- LaTeX Workshop

---

class: nord-dark, center, middle

# Q & A 🎤
