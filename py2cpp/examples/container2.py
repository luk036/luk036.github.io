#! /usr/bin/env python3


def main():
    S = set(["a", "e", "i", "o", "u", "e"])
    print(S)

    for i, e in enumerate(S):
        print("{}: {}, ".format(i, e))


if __name__ == "__main__":
    main()
