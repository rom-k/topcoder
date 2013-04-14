#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

n = int(sys.stdin.readline())

for num in range(n):
    n, k       = map(int, sys.stdin.readline().rstrip().split(" "))
    a, b, c, r = map(int, sys.stdin.readline().rstrip().split(" "))

    m = [a]
    for i in range(1, k):
        m.append((b * m[i-1] + c) % r)

    used = [0] * (k + 1)
    for i in range(k):
        if m[i] < k:
            used[m[i]] += 1

    def find_next_not_used(cur=0):
        nxt = cur
        while nxt < len(used) and used[nxt]:
            nxt += 1
        if nxt < len(used):
            used[nxt] += 1
        return nxt

    nxt = find_next_not_used()
    m.append(nxt)
    nxt = find_next_not_used(nxt)

    for i in range(k):
        if m[i] >= k or 1 < used[m[i]] or nxt < m[i]:
            if m[i] < k:
                used[m[i]] -= 1
            m[i] = nxt
            nxt = find_next_not_used(nxt)

    print "Case #" + str(num+1) + ":", m[(n - 1) % (k + 1)]

