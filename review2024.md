## Python

Version: 3.8 - 3.12 (current)
OS: Ubuntu, Windows, FydeOS, Android Termux

csdigit -> multiplierless
bairstow -> multiplierless
ellalgo -> multiplierless
ellalgo -> corr-solver
ellalgo -> netoptim
digraphx -> netoptim
digraphx -> nnsplace
mywheel -> digraphx
mywheel -> netlistx
netlistx -> nnsplace
netlistx -> ckpttnpy
physdes-py -> nnsplace
lds-gen -> physdes-py 
lds-gen -> bairstow 
lds-gen -> sphere-n
ec-gen -> ckpttnpy


numpy, scipy, networkx
┌───────┐┌───────────────┐┌──────────┐┌──────────────────────────────┐┌───────┐
│csdigit││ellalgo        ││mywheel   ││lds-gen                       ││ec-gen │
└┬──────┘└┬─┬───────────┬┘└┬────────┬┘└───────┬───────────┬─────────┬┘└──────┬┘
 │        │┌▽──────────┐│┌─▽──────┐┌▽───────┐┌▽─────────┐┌▽───────┐┌▽───────┐: 
 │        ││corr-solver│││digraphx││netlistx││physdes-py││bairstow││sphere-n│: 
 │        │└───────────┘│└─┬─────┬┘└─┬─────┬┘└┬─────────┘└┬───────┘└────────┘: 
 │        │   ┌─────────│──│─────│───│─────│──│───────────┘                  : 
 │        │   │         │  │     │  ┌│─────│──┘┌─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─┘ 
┌▽────────▽───▽┐┌───────▽──▽┐┌───▽──▽▽┐┌───▽───▽┐                              
│multiplierless││netoptim-py││nnsplace││ckpttnpy│    projgeom-py 
└──────────────┘└───────────┘└────────┘└────────┘                              

## Rust

num, ndarray, pet-graph

csd-rs
lds-rs -> lds-color
mywheel-rs
bairstow-rs 
ellalgo-rs -> netoptim-rs
physdes-rs
ecgen-rs
ckpttn-rs
fractions-rs -> projgeom-rs

## C++

csd -> multiplierless
ellalgo -> multiplierless
ellalgo -> "corr-solver"
bairstow -> multiplierless
ellalgo -> netoptim
physdes -> nnsplace
digraphx -> nnsplace
xnetwork -> netlistx
netlistx -> nnsplace
netlistx -> ckpttn
mywheel -> netlistx
mywheel -> digraphx
digraphx -> netoptim
"lds-gen" -> bairstow
"lds-gen" -> physdes 
"lds-gen" -> "sphere-n"
py2cpp -> mywheel
py2cpp -> xnetwork
ecgen -> ckpttn

┌───────┐┌───────────────────┐┌────────────────────────────┐┌─────────────────────────┐          
│csd-cpp││ellalgo-cpp        ││lds-gen-cpp                 ││py2cpp                   │          
└┬──────┘└┬─┬───────────────┬┘└┬────────────┬─────────────┬┘└──────────┬─────────────┬┘          
 │        │┌▽──────────────┐│┌─▽──────────┐┌▽───────────┐┌▽──────────┐┌▽───────────┐┌▽──────────┐
 │        ││corr-solver-cpp│││sphere-n-cpp││bairstow-cpp││physdes-cpp││xnetwork-cpp││mywheel-cpp│
 │        │└───────────────┘│└────────────┘└┬───────────┘└┬──────────┘└┬───────────┘└┬──────────┘
 │        │          ┌──────│───────────────│─────────────┘            │             │           
 │        │       ┌──│──────│───────────────┘   ┌──────────────────────│─────────────┘           
 │        │       │ ┌│──────┘     ┌─────────────│──────────────────────┘                         
┌▽────────▽───────▽┐││┌───────────▽┐┌───────────▽┐                                               
│multiplierless-cpp││││netlistx-cpp││digraphx-cpp│                                               
└──────────────────┘││└───┬───────┬┘└┬──┬────────┘                                               
           ┌────────││────│───────│──┘  │                                                        
           │┌───────┘└────│──┐    │     │                                                        
┌──────────▽▽┐┌───────────▽┐┌▽────▽─────▽┐                                                       
│netoptim-cpp││ckpttnpy-cpp││nnsplace-cpp│                                                       
└────────────┘└────────────┘└────────────┘                                                       

