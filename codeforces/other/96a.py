#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

s = sys.stdin.readline().strip()

prev = ""
cnt = 0
for c in s:
    if prev == c:
        cnt += 1
        if 7 <= cnt:
            print "YES"
            sys.exit()
    else:
        prev = c
        cnt = 1

print "NO"
