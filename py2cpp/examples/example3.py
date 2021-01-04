#! /usr/bin/env python3
import sys

def main(args):
    a = int(args[1])
    b = int(args[2])
    print('The answer is {}.'.format(a + b))

if __name__ == '__main__':
    main(sys.argv)
