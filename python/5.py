#!/usr/bin/python
# -*- coding: utf-8 -*-

a = ['cat', 'window', 'defenstrate']

for x in a:
    print x, len(x)

for x in a[:]:
    if len(x) > 6: a.append(x + "_add")

for x in a:
    print x, len(x)

