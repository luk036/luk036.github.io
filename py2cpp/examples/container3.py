#! /usr/bin/env python3

def print_test(C):
    print(C)

    for i, e in enumerate(C):
        print("{}: {}, ".format(i, e))


def main():
    L = ["a", "e", "i", "o", "u"]
    S = ("a", "e", "i", "o", "u")
    D = {4: 1.2, 5: 3.4}

    print_test(L)
    print_test(S)
    print_test(D)


if __name__ == '__main__':
    main()
