#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

s = map(int, sys.stdin.readline().strip().split())

m = {}
for i in range(4):
    m[s[i]] = 1

print 4 - len(m)
