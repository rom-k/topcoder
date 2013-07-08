#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

N, Q = map(int, sys.stdin.readline().strip().split(" "))

ans = "kogakubu10gokan"

for i in range(N):
    year, name = sys.stdin.readline().strip().split(" ")
    year = int(year)
    if year <= Q:
        ans = name

print ans

