#!/usr/bin/python
# -*- coding: utf-8 -*-

for n in range(2, 10):
    for x in range(2, n):
        if n % x == 0:
           print n, 'equals', x, '*', n/x
           break
    else:
         # 因数が見つからずにループが終了
         print n, 'is a prime number'

