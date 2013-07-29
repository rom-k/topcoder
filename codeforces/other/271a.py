#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

def is_distinct(x):
    s = str(x)
    mp = {}
    for x in s:
        if x in mp:
            return False
        mp[x] = 1
    return True

y = int(sys.stdin.readline().strip())

while True:
    y += 1
    if is_distinct(y):
        print y
        break
