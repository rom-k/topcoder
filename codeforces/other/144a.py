#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n = int(sys.stdin.readline().strip())
a = map(int, sys.stdin.readline().strip().split())

ma = max(a)
ma_index = 0
for i in range(n):
    if a[i] == ma:
        ma_index = i
        break

mi = min(a)
mi_index = 0
for i in reversed(range(n)):
    if a[i] == mi:
        mi_index = i
        break

steps = ma_index + (n - 1 - mi_index)
if mi_index < ma_index:
    steps -= 1

print steps

