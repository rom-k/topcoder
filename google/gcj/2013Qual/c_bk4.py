#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys


def is_palindrome(x):
    s = str(x)
    n = len(s)
    for i in xrange(n / 2):
        if s[n / 2 - 1 - i] != s[n - n / 2 + i]:
            return False
    return True


def make_palindromes2(n):
    p = []

    if 1 <= n:
        p.extend((1, 4, 9))

    b = []
    b2 = []
    for i in xrange(3, n + 1, 2):
        m = i / 2 + 1
        c = []

        if m % 2 == 0:
            if i == 3:
                b.append(1)
                b2.append(1)
            else:
                b = [x * 10 + y for y in xrange(2) for x in b]
                b2 = [x + y * 10 ** (m / 2 - 1) for y in xrange(2) for x in b]

#            for x, x2 in zip(b, b2):
#                c.append(x * 10 ** (m / 2) + x2)
#            c.append(2 * 10 ** (m - 1) + 2)

#        else:
#            for x, x2 in zip(b, b2):
#                for j in xrange(3):
#                    c.append(x * 10 ** (m / 2 + 1) + j * 10 ** (m / 2) + x2)
#            for j in xrange(3):
#                c.append(2 * 10 ** (m - 1) + j * 10 ** (m / 2) + 2)

        for j in c:
            j2 = j ** 2
            if is_palindrome(j2):
                p.append(j2)

    return p


def main():

    p = make_palindromes2(100)

    tt = int(sys.stdin.readline())

    for t in xrange(tt):
        a, b = map(int, sys.stdin.readline().rstrip().split(" "))

        ret = 0
        for x in p:
            if a <= x <= b:
                ret += 1

        print "Case #%d: %d" % (t + 1, ret)

if __name__ == '__main__':
    main()
