#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n = int(sys.stdin.readline().strip())
s = sys.stdin.readline().strip()

ret = 0
prev = ""
for c in s:
    if c == prev:
        ret += 1
    prev = c

print ret
