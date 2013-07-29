#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

w = sys.stdin.readline().strip()
a = ""

for i in range(len(w)):
    c = w[i]
    c = c.lower()

    if c == "a" or c == "o" or c == "y" or c == "e" or c == "u" or c == "i":
        continue

    a += "." + c

print a
