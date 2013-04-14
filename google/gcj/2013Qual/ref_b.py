#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import copy

tt = int(sys.stdin.readline())


class MyTree(object):

    def __init__(self):
        self.h = {}

    def _get_leaf(self, s, h=None):
        if h is None:
            h = self.h

        if len(s) == 0:
            return h
        else:
            if not h.has_key(s[0]):
                h[s[0]] = {}
            return self._get_leaf(s[1:], h[s[0]])

    def add(self, s):
        h = self._get_leaf(s)
        if not h.has_key('cnt'):
            h['cnt'] = 0
        h['cnt'] += 1



for t in range(tt):
    m = int(sys.stdin.readline())
    k1 = sys.stdin.readline().rstrip()
    k2 = sys.stdin.readline().rstrip()
    l = len(k1) / m

    s1 = [k1[l*x:l*(x+1)] for x in xrange(m)]
    s2 = [k2[l*x:l*(x+1)] for x in xrange(m)]

    print "DEBUG:::m=", m, ",l=", l
    print "DEBUG:::s1=", s1
    print "DEBUG:::s2=", s2

#    rets = []
#    if t % 2 == 0:
#        rets.append(k1)
#        rets.append(k2)

    tr = MyTree()
    tr.add(s1[0])

    print "Case #" + str(t+1) + ": IMPOSSIBLE"
#    rets.sort()
#    if rets:
#        print "Case #" + str(t+1) + ": " + rets[0]
#    else:
#        print "Case #" + str(t+1) + ": IMPOSSIBLE"
