#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

mod = 1000000007

tt = int(sys.stdin.readline())

for t in range(tt):
    n, k = map(int, sys.stdin.readline().rstrip().split(" "))
    a = map(int, sys.stdin.readline().rstrip().split(" "))

    a.sort()

    b = 1
    ret = 0
    for i in xrange(k-1, n):
        ret += a[i] * b
        ret %= mod

        b *= i+1
        b /= i+1-(k-1)

    print "Case #" + str(t+1) + ": " + str(ret)
