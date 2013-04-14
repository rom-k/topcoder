#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n = int(sys.stdin.readline())

for k, line in enumerate(sys.stdin):
    line = line.lower()

    colon = False
    low = 0
    high = 0
    for c in line:
        if c == ':':
            colon = True
            continue
        elif c == '(':
            high += 1
            if not colon: low += 1
        elif c == ')':
            low -= 1
            if not colon: high -= 1

        colon = False
        if low < 0: low = 0
        if high < 0: break

    if low == 0 and high >= 0:
        sys.stdout.write("Case #" + str(k+1) + ": YES\n")
    else:
        sys.stdout.write("Case #" + str(k+1) + ": NO\n")

