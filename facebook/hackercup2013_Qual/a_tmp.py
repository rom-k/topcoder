#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

def printt(t):
    sys.stdout.write("[")
    for x in t:
        sys.stdout.write("%2d," % x)
    sys.stdout.write("]\n")

scores = []
for i in range(1,27):
    scores.append(i)
scores = scores[23:] + scores[:23]
scores = scores[23:] + scores[:23]

#scores = [
#24, #a
#25, #b
#26, #c
#12, #d
#12, #e
#12, #f
#12, #g
#12, #h
#12, #i
#12, #j
#12, #k
#12, #l
#12, #m
#12, #n
#12, #o
#12, #p
#12, #q
#12, #r
#12, #s
#12, #t
#12, #u
#12, #v
#12, #w
#12, #x
#12, #y
#12, #z
#]

scores = [
24,
25,
26,

20,
21,
22,
23,

15,
16,
17,
18,
19,

9,
10,
11,
12,
13,
14,

2,
3,
4,
5,
6,
7,
8,

1,
]

printt(scores)
print ""

answers = [152, 754, 491, 729, 646]

strings = [
    "ABbCcc",
    "Good luck in the Facebook Hacker Cup this year!",
    "Ignore punctuation, please :)",
    "Sometimes test cases are hard to make up.",
    "So I just go consult Professor Dalves",
]

for i in range(len(strings)):
    strings[i] = strings[i].lower()

ts = []
for x in strings:
    t = [0] * 26

    for c in x:
        n = ord(c) - ord('a')
        if 0 <= n < 26:
            t[n] += 1

    printt(t)
    ts.append(t)

print ""
for i in range(len(strings)):
    t = ts[i]
    n = 0
    ret = 0
    for j in range(26):
        n += t[j]
        ret += t[j] * scores[j]
    print "#",i , "n=", n, "ret=", ret, "=>", answers[i], ":", 1.0 * (ret - answers[i]) / n

#print ""
#for i in range(len(strings)):
#    for j in range(len(strings)):
#        dif = 0
#        for k in range(26):
#            dif += abs(ts[i][k] - ts[j][k])
#        print dif,
#    print ""

print ""
printt([ts[1][k] - ts[2][k] for k in range(26)])
printt([ts[1][k] - ts[3][k] for k in range(26)])
printt([ts[1][k] - ts[4][k] for k in range(26)])
print ""
printt([ts[2][k] - ts[3][k] for k in range(26)])
printt([ts[2][k] - ts[4][k] for k in range(26)])
print ""
printt([ts[3][k] - ts[4][k] for k in range(26)])

