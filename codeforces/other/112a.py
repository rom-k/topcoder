#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

a = sys.stdin.readline().strip()
b = sys.stdin.readline().strip()

if a.lower() < b.lower():
    print -1
elif a.lower() == b.lower():
    print 0
else:
    print 1
