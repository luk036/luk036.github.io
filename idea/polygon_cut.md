# Rectilinear Polygon Creation and Decomposition

## Motivation

Mainly for VLSI Physical Design -> Rectilinear
e.g. 
- L-shaped Obstacles -> Cut into rectangle pieces
- Layout fracturing

Number of vertices is moderate, say less than 100 -> Accept O(n^2) algorithms.

Why rectilinear?

Integer coordinates

## Template method

Write for x == Write for y

## Design Patterns

## The Power of Canonical Form

- Simplify complicated algorithms

## New proposal

- Usual representation: Full-vertex list
- our: x-first, even-index list

## x-monotone, y-monotone, convexity

- is_x_monotone()
- is_y_monotone()
- is_convex() = is_x_monotone() && is_y_monotone()

## Hull of RPolygon

- rpolygon_make_xmonotone_hull(rpolygon)
- rpolygon_make_ymonotone_hull(rpolygon)
- rpolygon_make_convex_hull(rpolygon) = rpolygon_make_xmonotone_hull(rpolygon) + rpolygon_make_xmonotone_hull(rpolygon)

## Hull of Points

- create_x_monotone(points) (may not be canonical)
- create_y_monotone(points) (may not be canonical)

## Checking

Area check is not good enough.
Canonical check.

## Polygon Decomposition

Cut into rectangle pieces.

Break into three steps:
1. Cut into convex pieces first (in order to simpify the algorithms in the following two steps).
2. Then handle the explicit 270-degree vertices.
3. Then handle the implicit 270-degree vertices.

