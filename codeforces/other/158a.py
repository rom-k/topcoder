#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n, k = map(int, sys.stdin.readline().strip().split(" "))
a = map(int, sys.stdin.readline().strip().split(" "))

a.sort()
p = a[n - k]
if p <= 0:
    p = 1

c = 0
for x in a:
    if p <= x:
        c += 1

print c
