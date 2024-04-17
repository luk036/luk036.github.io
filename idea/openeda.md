# EDA开源化，是浪漫还是灾难？

# C/C++

```cpp
#define bool int
```

---

# make install

```bash
$ make
$ sudo make install
```

---

# dependency management

Skywater, open-pdk, magic
auto download

tensorflow
numpy -> openblas -> BLAS, LAPACK (C, Fortran)

# litex-conda-eda

https://opensource.antmicro.com/projects/litex-conda-eda

conda install python=3.7
conda install --channel "LiteX-Hub" \
 yosys \
 nextpnr \
 icestorm \
 iverilog \
 verilator \
 magic \
 vtr \
 open_pdks.sky130a \
 openroad \
 symbiyosys

# Unit Test
