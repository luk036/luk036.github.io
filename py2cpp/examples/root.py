#! /usr/bin/env python3
import sys
from math import sqrt

def main(args):
    a = float(args[1])
    b = float(args[2])
    c = float(args[3])
    if a == 0.:
        print('The answer is {}.'.format(-c / b))
        return
    b /= a
    c /= a
    hb = b / 2.
    d = hb * hb - c
    if d < 0.:
        print('No real solution.')
        return
    x1 = -hb + (sqrt(d) if hb < 0. else -sqrt(d))
    x2 = c / x1
    print('The answer is {} and {}'.format(x1, x2))

if __name__ == '__main__':
    main(sys.argv)
