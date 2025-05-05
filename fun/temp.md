title: 🍑 GitPod = GitHub + 🐧 Linux + VSCode
class: animation-fade
layout: true

<!-- This slide will serve as the base layout for all your slides -->

.bottom-bar[
{{title}}
]

---

class: impact

# {{title}}

👨🏻‍🏫 @luk036

---

## Why 🍑 GitPod.io?

- Remote working environment for software development
- Development on the go
- Cloud-based development
- Remote access to a (virtual) 🐧 Linux machine (docker's container) that has a 16-core CPU and 60GB RAM!
- The only requirements:
  - a web browser (better Chrome or Firefox)
  - an internet connection
  - a GitHub/GitLab account

---

## Technologies

- 🍑 GitPod's IDE is based on Eclipse Foundation's Theia, the same as VSCode.
- Experimental support of VSCode's extensions.
- Integrate with GitHub repositories.
- Docker's container as a virtual 🐧 Linux machine.
- Prebuilt Docker image contains basic software development tools such as:
- g++-8, clang++-10, python2, python3, gdb, npm, CMake, make
- More advanced images may include VNC or database facilities.

---

## Custom Configuration

- You may customize you own image build to make even more functionality, by modifying the `.gitpod.yml` file and `Dockerfile`.

- For example:
  - [jupyter lab](https://github.com/jins-tkomoda/dash-and-jupyter-notebook-with-gitpod)
  - [conda](https://github.com/mtvu/miniconda)
  - [latex + pandoc](https://github.com/luk036/ellipsoid-method)

---

## More examples

- C++ plus Conda
- Python plus Jupyter
- Pandoc + LaTeX

---

![gitpod](gitpod.png)

---

## Potential Usages 🚧

- Evaluate large open source github/gitlab repos.
- Perform benchmarking of large benchmarks
- Perform Sanitizer analysis, static code analysis
- Writing Undergraduate thesis via Pandoc
- Writing paper via Pandoc + LaTeX
- Hardware design simulation. EDA on the cloud.

---

## Limitations 😭

- Unused workspaces are automatically deleted after 30 days of inactivity.
- Only 100hrs/month, 4 parallel workspaces, public repos for free plan.
- No Windows or macOS build, only 🐧 Linux.
- Graphical output must be through VNC or JupyterLab. No sound.
- No GPU support.
- Debugging with IDE is not working 🤔

---

## XOR centric

- In fact, George Boole at first suggested to use ({0,1}, &, +) as his algebra
  system, but then gave up later for some unknown reason.
- f = 1 + a + a & b + a & b & c
- Boolean algebra is more intuitive for humans🚶, but computers are not humans🚶.
- In fact ancient geeks also use Boole's algebra.

---

## Why XOR

- XOR gate can be implemented effectively using _Pass-Transistor Logic_ (PTL)
- 5~6 transistors. Good for both power and delay.
- It has already successfully been used in for example full adder, encryption processor, Gray code encoder/decoder etc.
- Pass-Transistor Logic is relatively expensive for simple monotonic gates such as NAND and NOR (Zimmermann and Fichtner 1997).
- CMOS + PTL = CPL
- In fact, **all Boolean functions can be implemented using simply XOR-AND-NEG gates without OR gates**.

---

## Challenges

- Lack of supporting EDA tools. Almost need to redo everything.

---

## 🙋 Q & A
