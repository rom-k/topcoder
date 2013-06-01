#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import math

words = { }
for line in open('garbled_email_dictionary.txt'):
    for w in line.split( ):
        words.setdefault(w[0], [ ]).append(w)

ttt = int(sys.stdin.readline())

for tt in range(ttt):
    s = sys.stdin.readline().rstrip()

    ret = 0

    raise Exception()

    print "Case #%d: %d" % (tt + 1, ret)

