#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import math
import operator

mod = 1000002013

class Passengers:
    def __init__(self):
        self.o = 0
        self.e = 0
        self.p = 0

def calc_pay(n, o, e):
    d = e - o
    return d * n - d * (d - 1) / 2

ttt = int(sys.stdin.readline())

for tt in range(ttt):
    n, m = map(int, sys.stdin.readline().rstrip().split(" "))
    ps = [ ]
    for i in range(m):
        ps.append(Passengers())
        ps[i].o, ps[i].e, ps[i].p = map(int, sys.stdin.readline().rstrip().split(" "))

    ps.sort(key = operator.attrgetter('o'))

    ret = 0
    for i in range(m):
        ret += calc_pay(n, ps[i].o, ps[i].e) * ps[i].p
        ret %= mod

    inout = { }
    for i in range(m):
        inout.setdefault(ps[i].o, 0)
        inout.setdefault(ps[i].e, 0)
        inout[ps[i].o] += ps[i].p
        inout[ps[i].e] -= ps[i].p

    tkts = { }
    for s in sorted(inout.keys()):
        io = inout[s]
        if 0 < io:
            tkts.setdefault(s, 0)
            tkts[s] += io
        elif io < 0:
            io *= -1
            for o in reversed(sorted(tkts.keys())):
                t = min(io, tkts[o])
                ret -= calc_pay(n, o, s) * t
                tkts[o] -= t
                io -= t
                if io == 0:
                    break                
        else:
            pass

    ret = (ret + mod) % mod

    print "Case #%d: %s" % (tt + 1, ret)

