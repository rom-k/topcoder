#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
#import numpy as np
#import scipy

p = int(sys.stdin.readline())

ret = 1
for i in range(1, p):
    ret *= i
    ret %= 1000000007

print ret

