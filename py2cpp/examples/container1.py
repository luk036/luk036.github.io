#! /usr/bin/env python3


def main():
    L = ["a", "e", "i", "o", "u", "e"]
    print(L)

    for i, e in enumerate(L):
        print("{}: {}, ".format(i, e))


if __name__ == "__main__":
    main()
