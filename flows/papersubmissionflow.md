layout: true
class: typo, typo-selection

---

class: nord-dark, center, middle

# Paper Submission Flow (LaTeX + Git)

@luk036

---

## Why?

- Paper submission and publication

---

## Setting Up LaTeX Enviroment in Lubuntu

- sudo apt install:
  - git
  - texlive texlive-science
  - texlive-latex-extra (for biblatex)
  - latexmk chktex (for vcode)
  - latexdiff latexdiff-git

---

## Install Extensions of Visual Studio Code

- LaTeX Extension
- Git History

---

## Create GitHub for first publication

- For example: elliposid-method, add .gitignore (TeX)

- Clone to local directory:

```bash
> cd workspace/
> git clone https://github.com/luk036/ellipsoid-method.git
> cd ellipsoid-method
```

- Compared with the last version

```bash
> latexdiff-git --flatten --latexmk --pdf -r main.tex
```

---

## Before First revision

- Create a branch "revision"

```bash
> git branch revision
> git checkout revision
> git push --set-upstream origin revision
```

```terminal
> git log --oneline --all --decorate --graph
 a4b32b9 (HEAD -> revision, origin/revision) added hello
 3e33d7c removed (test)
 605f6ad (origin/master, origin/HEAD, master) added .clo
 b8c5ba3 added (test)
 324e4e8 add siam files
 cff3229 Initial commit
```

---

## How to submit revision paper

```bash
> latexdiff-git --flatten --latexmk --pdf -r master -r revision main.tex
```

The file `main-diffmaster-revision.pdf` is the file you want to submit.

- Note, maybe you only want to know which file changed:

```bash
> git diff master revision --name-only
> git diff master revision --name-status
```

---

## How to merge back to the origin/master

- First merge back to the master for the next round

```bash
> git checkout master
> git merge revision
> git commit -m "merge back"
> git push
```

- Continous on next revision

```bash
> git checkout master
```

---

class: nord-dark, center, middle

# 🙋 Q & A
