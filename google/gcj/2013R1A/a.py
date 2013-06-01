#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import math

ttt = int(sys.stdin.readline())

for tt in range(ttt):
    r, t = map(int, sys.stdin.readline().rstrip().split(" "))

    ret = int(math.floor((-2*r+1+math.sqrt(8*t+4*r*r-4*r+1))/4)) + 1
    while ret*(2*ret+2*r-1) > t:
        ret -= 1

    print "Case #%d: %s" % (tt + 1, ret)

