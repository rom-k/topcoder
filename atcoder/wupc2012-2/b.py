#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n = int(sys.stdin.readline())
s = sys.stdin.readline()

list = [( 1 if x == 'X' else 0 ) for x in s]

for i in range(3, n):
    list[i] += min(list[i-3:i])

print list[n-1]
