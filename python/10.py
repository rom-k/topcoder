#!/usr/bin/python
# -*- coding: utf-8 -*-


def make_incrementor(n):
    return lambda x: x + n

f = make_incrementor(42)

print f(0)
print f(1)
