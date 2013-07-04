#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

w = int(sys.stdin.readline().strip())

if w % 2 == 0 and w > 2:
    print "YES"
else:
    print "NO"
