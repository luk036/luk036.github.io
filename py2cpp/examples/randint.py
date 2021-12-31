#! /usr/bin/env python3
import sys
from random import randint


def main(args):
    a = int(args[1])
    b = int(args[2])
    c = randint(a, b)
    print("The answer is {}.".format(c))


if __name__ == "__main__":
    main(sys.argv)
