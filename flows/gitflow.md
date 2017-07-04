# git version control

## Installation

- sudo apt install git

## Create a web site from github

```terminal
> git config --global user.email "username@gmail.com"
> git clone https://github.com/username/username.github.io
> cd username.github.io/
> echo "Hello World" > index.html
> git add --all
> git commit -m "Initial commit"
> git commit -m "Initial commit"
> git push -u origin master
```
