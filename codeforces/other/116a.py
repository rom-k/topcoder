#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n = int(sys.stdin.readline().strip())
p = 0
ans = 0

for i in range(n):
    a, b = map(int, sys.stdin.readline().strip().split())
    p -= a
    p += b
    ans = max(ans, p)

print ans
