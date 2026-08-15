
# Code review

Vibe coding is good for beginners,
But "Software Engineering" is a must for long-term projects.
Loop Engineering

Playing game == Testing

## How does my AI-agent work?

Not consistent. nanobench

```rust
let even = n.is_multiple_of(2); 

let even = n % 2 == 0;
```

LDS rev_list

"If you can't validate, don't change."
e.g. Polygon's signed area (shoelace formula)
e.g. Recursive gcd is slower than iterative gcd?

Fix the warningss - Suppress warning messages.
Fix the unit tests - Change or even remove a unit test
Issue was pre-exist

## Design-for-AI

-  C++14 -> C++20

## Sometimes AI is not as Professional as you think

Fraction: I don't need the Division-by-zero check.
0/0















Either modify source code, or unit tests. But not both at the same time.
If AP changed, then "Don't modify the numerical values of the unit tests".

/fix-srt
/validate-srt


### Property-based tests

- x == x
- x * y == y * x
- x * (y * z) == (x * y) * z
- x * (y + z) == x * y + x * z

- area(convex_hull(P)) >= area(P)
- sum(area(polygon_cut(P))) == area(P)
- total_dual_cost <= total_primal_cost
- total_primal_cost <= 2 * total_dual_cost

- is_bipartite(max_cut(G))
- is_bipartite(odd_cycle_cover(G))
- is_hamiltonian_cycle(tsp(point_set))

### Round-trip tests

- docode(encode(x)) == x
- inv_spectral_fact(spectral_fact(r)) == r
- poly(roots(p)) == p
- to_decimal(to_csd(n)) == n
- p + v - v == p

Not 100% guarantee but useful for AI.

