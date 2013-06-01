#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

tt = int(sys.stdin.readline())

for t in range(tt):
    n, m = map(int, sys.stdin.readline().rstrip().split(" "))

    h = []
    for i in range(n):
        h.append(map(int, sys.stdin.readline().rstrip().split(" ")))

    r_max = []
    c_max = []
    for i in range(n):
        r_max.append(max(h[i]))
    for i in range(m):
        c_max.append(max([x[i] for x in h]))

    ret = "YES"
    for r in range(n):
        for c in range(m):
            if h[r][c] < min(r_max[r], c_max[c]):
                ret = "NO"
                break
        else:
            continue
        break

    print "Case #%d: %s" % (t + 1, ret)
