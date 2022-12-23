# Modules summary

<!--
*threadpool -> bairstow
*xtl -> *xtensor
*xtensor -> *xtensor-blas
ellalgo -> lmi-solver
*xtensor -> ellalgo
*xtensor-blas -> lmi-solver
lmi-solver -> corr-solver
ellalgo -> multiplierless
bairstow -> multiplierless
ellalgo -> netoptim
py2cpp -> xnetwork
xnetwork -> netoptim
netoptim -> ckpttn
*boost -> ckpttn
netoptim -> nnsplace
fractions -> projgeom
-->

```
┌───────────┐┌────┐┌──────┐┌──────┐┌─────────┐
│*threadpool││*xtl││py2cpp││*boost││fractions│
└┬──────────┘└┬───┘└─┬────┘└───┬──┘└┬────────┘
┌▽───────┐┌───▽────┐┌▽────────┐│┌───▽────┐    
│bairstow││*xtensor││xnetwork │││projgeom│    
└┬───────┘└┬───┬───┘└────────┬┘│└────────┘    
 │┌────────▽─┐┌▽────────────┐│ │              
 ││ellalgo   ││*xtensor-blas││ │              
 │└───────┬┬┬┘└───────────┬─┘│ │              
 │        │││             │  └┐│              
 │        └││─────────────│──┐││              
 │         │└────┐        │  ││└──────┐       
┌▽─────────▽───┐┌▽────────▽┐┌▽▽──────┐│       
│multiplierless││lmi-solver││netoptim││       
└──────────────┘└┬─────────┘└┬──┬────┘│       
┌────────────────▽┐┌─────────▽┐┌▽─────▽┐      
│corr-solver      ││nnsplace  ││ckpttn │      
└─────────────────┘└──────────┘└───────┘      
```
