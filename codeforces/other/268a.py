#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n = int(sys.stdin.readline().strip())
h = []
a = []
for i in range(n):
    x, y = map(int, sys.stdin.readline().strip().split())
    h.append(x)
    a.append(y)

count = 0
for i in range(n):
    for j in range(n):
        if i != j and h[i] == a[j]:
            count += 1

print count
