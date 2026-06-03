# Validation in AI Era 

Reasonable?
AI doesn't know what Reasonable is.

If you can't validate, don't change.
e.g. Recursive gcd is slower than iterative gcd?

Either modify source code, or unit tests. But not both at the same time.
If AP changed, then "Don't modify the numerical values of the unit tests".

/fix-srt
/validate-srt

### Round-trip tests

- docode(encode(x)) == x
- inv_spectral_fact(spectral_fact(r)) == r
- poly(roots(p)) == p
- to_decimal(to_csd(n)) == n
- p + v - v == p

### Property-based tests

- x == x
- x * y == y * x
- x * (y * z) == (x * y) * z
- x * (y + z) == x * y + x * z

- area(convex_hull(P)) >= area(P)
- sum(area(polygon_cut(P))) == area(P)
- total_dual_cost <= total_primal_cost

- is_bipartite(max_cut(G))
- is_bipartite(odd_cycle_cover(G))
- is_hamiltonian_cycle(tsp(point_set))

Not 100% guarantee but useful for AI.

