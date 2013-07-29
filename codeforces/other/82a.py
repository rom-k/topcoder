#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

names = ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"]
name_counts = len(names)

n = int(sys.stdin.readline().strip())
cans_bought = 0

loop = 0
while 1:
    loop += 1
    cans_buy = 2 ** (loop - 1)

    if n <= cans_bought + name_counts * cans_buy:
        cans_remain = n - cans_bought
        whos_buy = (cans_remain - 1) / cans_buy
        print names[whos_buy]
        break

    cans_bought += name_counts * cans_buy
