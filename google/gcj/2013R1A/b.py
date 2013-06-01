#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import math

tt = int(sys.stdin.readline())

for t in range(tt):
    ee, r, n = map(int, sys.stdin.readline().rstrip().split(" "))
    v = map(int, sys.stdin.readline().rstrip().split(" "))

    e = ee
    ret = 0
    for i in range(n):
        e = min(e + r, ee)
        s = 0
        for j in range(1, min(n-i, ee / r + 2)):
            if v[i] < v[i+j]:
                s = max(s, ee - r * j)
        if e < s:
            s = e
        ret += v[i] * (e - s)
        e = s

    print "Case #%d: %s" % (t + 1, ret)

