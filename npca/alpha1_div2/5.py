#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

col = sys.stdin.readline().split()
n = int(col[0])
m = int(col[1])

ret = 0

for i in range(n):
    col = sys.stdin.readline().split()
    a = int(col[0])
    b = int(col[1])
    if a <= m and m <= b:
        ret += 1

print ret
