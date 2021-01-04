#! /usr/bin/env python3
import sys

def main(args):
    a = float(args[1])
    b = float(args[2])
    a, b = b, a  # swap
    print('The answer is {}.'.format(a - b))

if __name__ == '__main__':
    main(sys.argv)
