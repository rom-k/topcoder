#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
#import numpy as np

line = sys.stdin.readline()
col = line.split()
n = int(col[0])
m = int(col[1])

# can't use NumPy on atcoder
c = [[0 for i in range(m)] for i in range(n)]
#c = np.zeros((n, m))

for i in range(n):
    line = sys.stdin.readline()
    for j in range(m):
        if (line[j].isdigit()):
            c[i][j] = int(line[j])
        else:
            c[i][j] = -100000

ret = 0
for i in range(n):
    for j in range(m):
        for k in range(1, min(n-i, m-j)+1):
            syl = (i, i, i+k-1, i+k-1)
            sxl = (j, j+k-1, j+k-1, j)
            dyl = (1, 1, -1, -1)
            dxl = (1, -1, -1, 1)
            for o in range(4):
                sy = syl[o]
                sx = sxl[o]
                dy = dyl[o]
                dx = dxl[o]
                sum = 0
                for p in range(k):
                    for q in range(k):
                        if k <= p + q: break
                        sum += c[sy+p*dy][sx+q*dx]
                ret = max(ret, sum)

print int(ret)
