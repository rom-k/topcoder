#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

p = sys.stdin.readline().strip()

for c in p:
    if c == "H" or c == "Q" or c == "9":
        print "YES"
        sys.exit()

print "NO"
