#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import math

tt = int(sys.stdin.readline())

def is_palindrome(x):
    s = str(x)
    for i in range(len(s) / 2):
        if s[i] != s[len(s)-i-1]:
            return False
    return True

for t in range(tt):
    a, b = map(int, sys.stdin.readline().rstrip().split(" "))

    ret = 0
    for i in range(int(math.ceil(math.sqrt(a))), int(math.sqrt(b)) + 1):
        if is_palindrome(i) and is_palindrome(i**2):
            ret += 1

    print "Case #%d: %d" % (t + 1, ret)
