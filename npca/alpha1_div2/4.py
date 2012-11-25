#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

col = sys.stdin.readline().split()
n = int(col[0])
m = int(col[1])

friend = []

for i in range(n):
    friend.append([])
    for j in range(m):
        a = sys.stdin.readline()
        a = a.rstrip()
        a = int(a) if a.isdigit() else 0
        friend[i].append(int(a))

sum = 0
for j in range(m):
    b = friend[0][j]
    for i in range(1, n):
        b = max(b, friend[i][j])
    sum += b

print sum
