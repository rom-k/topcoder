#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n = int(sys.stdin.readline().strip())
a = map(int, sys.stdin.readline().strip().split())

a.sort()
a.reverse()
full_total = sum(a)

total = 0
for i in range(n):
    x = a[i]
    total += x
    if total > full_total / 2:
        print i + 1
        sys.exit()
