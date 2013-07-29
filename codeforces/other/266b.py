#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n, t = map(int, sys.stdin.readline().strip().split())
s = sys.stdin.readline().strip()

for i in range(t):
    s_new = s
    for j in range(n - 1):
        if s[j] == "B" and s[j + 1] == "G":
            s_new = s_new[:j] + "GB" + s_new[j + 2:]
    s = s_new

print s
