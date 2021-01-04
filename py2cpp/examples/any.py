#! /usr/bin/env python3


def print_test(C):
    print(C)
    for i, e in enumerate(C):
        print("{}: {}, ".format(i, e))


if __name__ == '__main__':
    D = {4: 1, 5: 3.4, 9: "hello"}
    print_test(D)
    print(D[9])
