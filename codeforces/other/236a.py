#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

s = sys.stdin.readline().strip()

mp = {}
for x in s:
    mp[x] = 1

if len(mp) % 2 == 0:
    print "CHAT WITH HER!"
else:
    print "IGNORE HIM!"
