#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n = int(sys.stdin.readline().strip())
s = map(int, sys.stdin.readline().strip().split())

c = [0, 0, 0, 0, 0]
for i in range(n):
    c[s[i]] += 1

t = 0
t += c[4]
c[1] -= min(c[1], c[3])
t += c[3]
t += (c[2] * 2 + c[1]) / 4
if (c[2] * 2 + c[1]) % 4 != 0:
    t += 1

print t
