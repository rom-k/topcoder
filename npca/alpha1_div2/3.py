#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n = sys.stdin.readline()
n = int(n)
ans = []
ok = 0

for x in range(n):
    ans.append(sys.stdin.readline())

for x in range(n):
    rep = sys.stdin.readline()
    if ans[x] == rep:
        ok += 1

print ok
