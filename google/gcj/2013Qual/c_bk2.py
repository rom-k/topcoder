#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import math

def num2binstr(b, k = None):
    s = format(b, 'b')
    while k and len(s) < k:
        s = "0" + s
    return s

def is_palindrome(x):
    s = str(x)
    n = len(s)
    for i in xrange(n / 2):
        if s[n / 2 - 1 - i] != s[n - n / 2 + i]:
            return False
    return True

def make_palindrome_candidate_roots(m):
    m2 = m / 2 + 1
    m3 = m2 / 2
    r = []
    if m % 2 == 0:
        pass
    elif m2 == 1:
        r.extend((1, 2, 3))
    elif m2 == 2:
        r.extend((11, 22))
    elif m2 % 2 == 0:
        for i in range(2 ** (m3 - 1)):
            s = "1" + num2binstr(i, m3 - 1)
            s = s + s[::-1]
            r.append(int(s))
        r.append(int("2" + num2binstr(0, m2 - 2) + "2"))
    else:
        r2 = make_palindrome_candidate_roots(m - 2)
        for i in r2:
            s = str(i)
            s = s[:m3]
            for j in range(3):
                r.append(int(s + str(j) + s[::-1]))

    return r

def make_palindromes(m):
    r = make_palindrome_candidate_roots(m)

    l = []
    for i in r:
        if is_palindrome(i**2):
            l.append(i**2)

    return l

def main():
    tt = int(sys.stdin.readline())

    for t in xrange(tt):
        a, b = map(int, sys.stdin.readline().rstrip().split(" "))

        ka = int(math.log10(a)) + 1
        kb = int(math.log10(b)) + 1

        l = []
        for k in range(ka, kb + 1):
            l.extend(make_palindromes(k))

        l = [x for x in l if a <= x <= b]
        ret = len(l)

        print "Case #%d: %d" % (t + 1, ret)

if __name__ == '__main__':
    main()
