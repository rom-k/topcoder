#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n = int(sys.stdin.readline())

for k, line in enumerate(sys.stdin):
    line = line.lower()

    t = [0] * 26
    for c in line:
        n = ord(c) - ord('a')
        if 0 <= n < 26:
            t[n] += 1

    t.sort()

    s = 0
    for i in range(26):
        s += (i + 1) * t[i]

    sys.stdout.write("Case #")
    sys.stdout.write(str(k))
    sys.stdout.write(": ")
    print s

