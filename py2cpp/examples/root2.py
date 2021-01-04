#! /usr/bin/env python3
import sys
from math import sqrt


def find_roots(a, b, c):
    assert a != 0.
    b /= a
    c /= a
    hb = b / 2.
    d = hb * hb - c
    if d < 0.:
        return None
    x1 = -hb + (sqrt(d) if hb < 0. else -sqrt(d))
    x2 = c / x1
    return x1, x2


def main(args):
    a = float(args[1])
    b = float(args[2])
    c = float(args[3])

    if a == 0.:
        print('The answer is {}.'.format(-c/b))
        return
    ans = find_roots(a, b, c)
    if ans is None:
        print('No real solution.')
    else:
        print('The answer is {}.'.format(ans))


if __name__ == '__main__':
    main(sys.argv)
