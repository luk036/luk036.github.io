## Python

**Version**: 3.8 - 3.12 (current)
**OS**: Ubuntu, Windows, FydeOS, Android Termux

### Package Dependencies
- csdigit → multiplierless
- ginger → multiplierless
- ellalgo → multiplierless
- ellalgo → corr-solver
- ellalgo → netoptim
- digraphx → netoptim
- digraphx → nnsplace
- mywheel → digraphx
- mywheel → netlistx
- netlistx → nnsplace
- netlistx → ckpttnpy
- physdes-py → nnsplace
- lds-gen → physdes-py
- lds-gen → ginger
- lds-gen → sphere-n
- ec-gen → ckpttnpy

### Core Libraries
numpy, scipy, networkx

### Package Relationships Diagram
```
┌───────┐┌───────────────┐┌──────────┐┌──────────────────────────────┐┌───────┐
│csdigit││ellalgo        ││mywheel   ││lds-gen                       ││ec-gen │
└┬──────┘└┬─┬───────────┬┘└┬────────┬┘└───────┬───────────┬─────────┬┘└──────┬┘
 │        │┌▽──────────┐│┌─▽──────┐┌▽───────┐┌▽─────────┐┌▽───────┐┌▽───────┐:
 │        ││corr-solver│││digraphx││netlistx││physdes-py││ginger  ││sphere-n│:
 │        │└───────────┘│└─┬─────┬┘└─┬─────┬┘└┬─────────┘└┬───────┘└────────┘:
 │        │   ┌─────────│──│─────│───│─────│──│───────────┘                  :
 │        │   │         │  │     │  ┌│─────│──┘┌─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─┘
┌▽────────▽───▽┐┌───────▽──▽┐┌───▽──▽▽┐┌───▽───▽┐
│multiplierless││netoptim-py││nnsplace││ckpttnpy│    projgeom-py
└──────────────┘└───────────┘└────────┘└────────┘    rat-trig
```

## Rust

### Core Libraries
num, ndarray, pet-graph

### Package Dependencies
- csd-rs
- lds-rs → lds-color
- mywheel-rs
- mywheel-rs → digraphx-rs
- ginger-rs
- ellalgo-rs → netoptim-rs
- physdes-rs
- ecgen-rs
- ckpttn-rs
- fractions-rs → projgeom-rs
- fractions-rs → rat-trig-rs

## C++

### Package Dependencies
- csd → multiplierless
- ellalgo → multiplierless
- ellalgo → "corr-solver"
- ginger → multiplierless
- ellalgo → netoptim
- physdes → nnsplace
- digraphx → nnsplace
- xnetwork → netlistx
- netlistx → nnsplace
- netlistx → ckpttn
- mywheel → netlistx
- mywheel → digraphx
- digraphx → netoptim
- "lds-gen" → ginger
- "lds-gen" → physdes
- "lds-gen" → "sphere-n"
- py2cpp → mywheel
- py2cpp → xnetwork
- ecgen → ckpttn

### Package Relationships Diagram
```
┌───────┐┌───────────────────┐┌────────────────────────────┐┌─────────────────────────┐
│csd-cpp││ellalgo-cpp        ││lds-gen-cpp                 ││py2cpp                   │
└┬──────┘└┬─┬───────────────┬┘└┬────────────┬─────────────┬┘└──────────┬─────────────┬┘
 │        │┌▽──────────────┐│┌─▽──────────┐┌▽───────────┐┌▽──────────┐┌▽───────────┐┌▽──────────┐
 │        ││corr-solver-cpp│││sphere-n-cpp││ginger-cpp  ││physdes-cpp││xnetwork-cpp││mywheel-cpp│
 │        │└───────────────┘│└────────────┘└┬───────────┘└┬──────────┘└┬───────────┘└┬──────────┘
 │        │          ┌──────│───────────────│─────────────┘            │             │
 │        │       ┌──│──────│───────────────┘   ┌──────────────────────│─────────────┘
 │        │       │ ┌│──────┘     ┌─────────────│──────────────────────┘
┌▽────────▽───────▽┐││┌───────────▽┐┌───────────▽┐
│multiplierless-cpp││││netlistx-cpp││digraphx-cpp│            fractions-cpp
└──────────────────┘││└───┬───────┬┘└┬──┬────────┘            projgeom-cpp
           ┌────────││────│───────│──┘  │                     rat-trig-cpp
           │┌───────┘└────│──┐    │     │
┌──────────▽▽┐┌───────────▽┐┌▽────▽─────▽┐
│netoptim-cpp││ckpttn-cpp  ││nnsplace-cpp│
└────────────┘└────────────┘└────────────┘
```
