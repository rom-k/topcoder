#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n = int(sys.stdin.readline().strip())
ans = 0

for i in range(n):
    a = map(int, sys.stdin.readline().strip().split())
    if 2 <= sum(a):
        ans += 1

print ans
