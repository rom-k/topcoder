#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n = int(sys.stdin.readline().strip())
p = map(int, sys.stdin.readline().strip().split())
r = [0 for i in range(n)]

for i in range(n):
    r[p[i] - 1] = i + 1

for i in range(n):
    print r[i],

print ""
