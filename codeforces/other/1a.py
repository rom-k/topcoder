#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n, m, a = map(int, sys.stdin.readline().strip().split(" "))

x = n / a + (1 if n % a else 0)
y = m / a + (1 if m % a else 0)

print x * y
