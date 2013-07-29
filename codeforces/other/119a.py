#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

def gcd(a, b):
    return gcd(b, a % b) if b else a

a, b, n = map(int, sys.stdin.readline().strip().split())

while 1:
    taken = gcd(n, a)
    n -= taken
    if n <= 0:
        print 0
        break
    taken = gcd(n, b)
    n -= taken
    if n <= 0:
        print 1
        break
