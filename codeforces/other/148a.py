#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

k = int(sys.stdin.readline().strip())
l = int(sys.stdin.readline().strip())
m = int(sys.stdin.readline().strip())
n = int(sys.stdin.readline().strip())
d = int(sys.stdin.readline().strip())

ret = 0
for i in xrange(1, d + 1):
    if i % k == 0 or i % l == 0 or i % m == 0 or i % n == 0:
        ret += 1

print ret
