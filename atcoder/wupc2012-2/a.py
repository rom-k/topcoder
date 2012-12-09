#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

line = sys.stdin.readline()
col = line.split()
n = int(col[0])
m = int(col[1])

x = 0
for i in range(n+1):
    x += i*i

print x % m
