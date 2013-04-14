#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

mod = 1000000007

tt = int(sys.stdin.readline())

for t in range(tt):
    n, k = map(int, sys.stdin.readline().rstrip().split(" "))
    a = map(int, sys.stdin.readline().rstrip().split(" "))

#    print "DEBUG:::", n
#    print "DEBUG:::", k
#    print "DEBUG:::", a[0]
#    print "DEBUG:::", a[1]
    a.sort()
#    print "DEBUG:::", a
#    print "DEBUG::: n=", n
#    print "DEBUG::: k=", k
#    print "DEBUG::: len(a)=", len(a)

    b = 1
    ret = 0
#    for i in range(k-1, n):
    for i in xrange(k-1, n):
#        print "DEBUG:::", i
#        print "DEBUG:::", str(a[i]) + " * " + str(b) + " = " + str(a[i] * b)
        ret += a[i] * b
        ret %= mod

        b *= i+1
        b /= i+1-(k-1)
#        b %= mod

#    sys.stdout.write("Case #")
#    sys.stdout.write(str(k))
#    sys.stdout.write(": ")
    print "Case #" + str(t+1) + ": " + str(ret)
