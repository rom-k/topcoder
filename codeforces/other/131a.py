#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

w = sys.stdin.readline().strip()

if w == w.upper():
    w = w.lower()
elif w[1:] == w[1:].upper():
    w = w[0].upper() + w[1:].lower()

print w
