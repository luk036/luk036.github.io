# No Nonsense Global Placer

## Motivation

Target density???

50 years' problem
Seem have a solution
Someone say, "oh, I know the reason."
Everything is fine.
Everything is under control.
Today's global placers are too complicated.

## ✨ Features

- Simple (yet effective)
- No floating point arithmetic is needed if linear cost model is assumed.
- Support monotonic cost models (including concave)
- No clustering effect and hence predictable (avoid detour of global routing)

# What is the congestion problem?

If the problem is "not enough routing resource", then it is easy to fix.

## Flow-based algorithm

If linear cost model is assumed, then use Howard's algorithm.

## I/O placement

# Notations

Let $c$ is the cost function.
Furthermore, we assume that it is separable so that $c = c_x + c_y$.

The min-max formulation:

# Comparison (no clustering in the congestion map)
