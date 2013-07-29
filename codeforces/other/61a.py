#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

a = sys.stdin.readline().strip()
b = sys.stdin.readline().strip()
c = ""

for x, y in zip(a, b):
    if x == y:
        c += "0"
    else:
        c += "1"

print c
