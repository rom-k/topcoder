#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import math

ttt = int(sys.stdin.readline())

def comb(n, r):
    return math.factorial(n) / math.factorial(r) / math.factorial(n-r)

for tt in range(ttt):
    n, x, y = map(int, sys.stdin.readline().rstrip().split(" "))
    x = abs(x)

    ret = 0.0
    k = (x + y) / 2 + 1
    a = (k - 1) * (2 * (k - 1) - 1)
    b =  k      * (2 *  k      - 1)
    if n <= a:
        pass
    elif b <= n:
        ret = 1.0
    else:
        c = n - a
        if x == 0:
            pass
        elif x + 2 * y < c:
            ret = 1.0
        else:
            for i in range(y + 1, c + 1):
                ret += comb(c, i)
            ret *= 0.5 ** c

    print "Case #%d: %s" % (tt + 1, ret)

