#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n = int(sys.stdin.readline().strip())

a = []
for i in range(n):
    a.append(sys.stdin.readline().strip())

for i in range(n):
    w = a[i]

    if len(w) <= 10:
        print w
    else:
        print "%s%d%s" % (w[0], len(w) - 2, w[-1])
