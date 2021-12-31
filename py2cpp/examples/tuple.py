#! /usr/bin/env python3


def main():
    T = ("a", "e", "i", "o", "u", "e", 7, 3.4)
    print(T)

    for i, e in enumerate(T):
        print("{}: {}, ".format(i, e))


if __name__ == "__main__":
    main()
