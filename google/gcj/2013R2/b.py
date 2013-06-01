#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import math

ttt = int(sys.stdin.readline())

def could(n, p):
    b = [ ]
    for i in range(n):
        b.append(p % 2)
        p /= 2

    w = 0
    zaw = 0
    for i in range(n)[::-1]:
        if w == 0 and b[i] == 1:
            w = 1
        if w == 1 and b[i] == 0:
            zaw = 1

    if zaw == 1:
        w = 0
        for i in range(n)[::-1]:
            if w == 0 and b[i] == 1:
                b[i] = 0
                w = 1
            elif w == 1 and b[i] == 0:
                b[i] = 1

    r = 0
    for i in range(n):
        r *= 2
        r += b[i]

    return r

for tt in range(ttt):
    n, p = map(int, sys.stdin.readline().rstrip().split(" "))
    p -= 1

    c = could(n, p)
    g = 0
    if p == 2 ** n - 1:
        g = 2 ** n - 1
    else:
        g = 2 ** n - 2 - could(n, 2 ** n - 2 - p)

    print "Case #%d: %d %d" % (tt + 1, g, c)

