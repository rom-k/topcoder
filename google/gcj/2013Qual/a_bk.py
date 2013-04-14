#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import re

tt = int(sys.stdin.readline())

for t in range(tt):
    l = []

    for i in range(4):
        l.append(sys.stdin.readline().rstrip())
    sys.stdin.readline()

    re_win_x = re.compile(r"[TX]{4}")
    re_may_x = re.compile(r"[TX\.]{4}")
    re_win_o = re.compile(r"[TO]{4}")
    re_may_o = re.compile(r"[TO\.]{4}")

    win_o = False
    may_o = False
    win_x = False
    may_x = False

    def check(str):
        global win_o
        global may_o
        global win_x
        global may_x

        if isinstance(str, list):
            str = "".join(str)

        if re_win_o.match(str):
            win_o = True
        if re_may_o.match(str):
            may_o = True
        if re_win_x.match(str):
            win_x = True
        if re_may_x.match(str):
            may_x = True

    for r in range(4):
        check(l[r])
    for c in range(4):
        check([x[c] for x in l])
    check([l[i][i] for i in range(4)])
    check([l[i][3 - i] for i in range(4)])

    r = ""
    if not may_o and not may_x:
        r = "Draw"
    elif not win_o and not win_x:
        r = "Game has not completed"
    elif win_o:
        r = "O won"
    else:
        r = "X won"

    print "Case #%d: %s" % (t + 1, r)
