class: middle, center

# Lubuntu 17.04

---

## Why

- clang 4.0
- Latest g++ 7.0 version
- pandoc 1.19

---

## Tools

- Dropbox/NutStore (JianGuoYun)

- Visual Studio Code (vcode)

- Firefox (web browser)

- git

---

## Issues

1. Can't install package from .deb file.
   Sol'n: use `sudo dpkg -i` to install and `sudo apt install -f` to fix the dependence problem
2. Can't run Visual Studio Code.
   Sol'n: run `code` at terminal and see which libraries are missing. Then use `sudo apt install` to install the missing ones.
3. Can't set "synchromize date & time with internet servers".
   Sol'n: install NTP using `sudo apt install ntp`
4. Can't use Chinese Input method.
   Sol'n: install `Ibus` instead of using `Fcitx`.
   - Add Chinese in Preference -> Language Support
   - Type `sudo apt install ibus ibus-pinyin`
5. Install flashplayer
    - `sudo apt install flashplugin-installer`

---

## Useful keyboard shortcuts

- `Ctrl-Alt-T`: open Terminal

- `Ctrl-Alt-Del`: open Task Manager

- `Alt-Tab`: Switch window

- `Win-D`

---

## Useful Terminal Commands

- `df`

- `sudo apt install`

---

## Backslide

- Download node-v6.11.0-linux-x64.tar.xz
- Decompress the file
- cd node-v6.11.0-linux-x64/
- sudo cp -r * /usr
- sudo npm install -g backslide
- cd workspace/
- bs init
- bs serve
