#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import math

ttt = int(sys.stdin.readline())

for tt in range(ttt):
    a, n = map(int, sys.stdin.readline().rstrip().split(" "))
    b = map(int, sys.stdin.readline().rstrip().split(" "))

    ret = n
    if a != 1:
        b = sorted(b)
        add = 0
        for i in range(n):
            if b[i] < a:
                a += b[i]
            else:
                ret = min(ret, add + n-i)
                while a <= b[i]:
                    a += a-1
                    add += 1
                a += b[i]
        ret = min(ret, add)

    print "Case #%d: %s" % (tt + 1, ret)

