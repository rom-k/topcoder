#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n = 5

ret = -1
for i in range(n):
    col = map(int, sys.stdin.readline().strip().split())
    for j in range(n):
        if col[j] == 1:
            ret = abs(2 - i) + abs(2 - j)

print ret
