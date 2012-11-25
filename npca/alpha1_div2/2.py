#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

a = 1000005

sys.stdin.readline()

for line in sys.stdin:
    a = min(int(line), a)

print str(a)
