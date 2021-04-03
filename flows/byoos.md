layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Bring Your Own Operating System

## @luk036

---

## Current: BYOD

- Bring Your Own Device at work.
- Work with the device you are familiar:
    - Ultrabook, Chromebook, MacBook, Ubuntubook.
- Keep your own personal Data:
    - Passwords, bookmarks, browsing history
- Office/School provides only the internet connection.

---

## Future: BYOOS

- Brin Your Own Operating System at work.
- Keep your laptops at home/office.
- Work with the OS you are familiar with:
    - Lubuntu, Kubuntu, Android, MacOS, ChromeOS, GitPod, etc.
- Keep Personal Data:
    - Passwords, bookmarks, browsing history
- Office/School provides the basic hardware and internet connection.

---

## Solution: Live USB and Docker

- History: Demo CD from Magazine
- Now, USB and Docker

---

## Tools

- Multi-boot USB Creator (e.g. Easy2Boot)
- Miniconda
- Cloud Storage:
    - Onedrive, Dropbox, Jianguoyun
    - GitHub

---

## Microsoft Office Issue

- E-mail Attachment - Forward to Outlook account
- Upload to Onedrive/Jianguoyun

---

## Why USB Live?

- Share a single laptop for a whole family.
- Shared workspace/Library/Internet Cafe.

---

## Preparation

- USB 3.0 (although USB 2.0 is ok too).
- Minimum 8Gb. Better 64Gb.
- Internet Connection.
- A Laptop/PC computer.

---

## Installation

1. Partition a portion of USB for local storage (optional)
2. Download the iso image from the offical website (better via torrent).
3. Download the usb creator software such as `Easy2Boot`.

---

## Reboot from USB

- press `F12` during boot
- Select "Linux distributions" from menu
- Select "Try Lubuntu without installing" (don't install)
- Select "English" (default)

---

## Known issues of .iso + persistence:

- Can't upgrade Linux kernel
- Can't install docker

---

## Why GitPod

- Do one thing at a time and do it right.

---

## Comparison

| OS                  | Kernel     | Shell       | Terminal   | DE   | Memory  |
| ------------------- | ---------- | ----------- | ---------- | ---- | ------- |
| Lubuntu 18.04 LTS   | 4.15.0-20  | bash 4.4.20 | lxterminal | LXDE | 290MiB  |
| Lubuntu Focal Fossa | 4.15.0-20  | bash 5.0.16 | lxterminal | LXQt | 454MiB  |
| PrimeOS (Android 7) | 4.14.15    | bash 5.0.16 | termux     | NA   | 860MiB  |
| BlissOS (Android 9) | 4.19.50    | bash 5.0.16 | termux     | NA   | 860MiB  |
| Red Mi (Android 9)  | 4.9.117+   | bash 5.0.16 | termux     | NA   | 1341MiB |
| Windows 10 Pro      | 10.0.18363 | Powershell  | NA         | Aero | 2063MiB |
| Windows 10 Home     | 10.0.18363 | Powershell  | NA         | Aero | 2040MiB |

---

## Future Work

- VPN
- Wifi Hotspot

---

class: nord-dark, center, middle

# Q & A 🗣️
