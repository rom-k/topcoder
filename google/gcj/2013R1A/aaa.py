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
    re_win_o = re.compile(r"[TO]{4}")
    re_not_fin = re.compile(r"[\.]")

    win_o = False
    win_x = False
    finished = True

    def check(str):
        global win_o
        global win_x
        global finished

        if isinstance(str, list):
            str = "".join(str)

        if re_win_o.match(str):
            win_o = True
        if re_win_x.match(str):
            win_x = True
        if re_not_fin.search(str):
            finished = False

    for r in range(4):
        check(l[r])
    for c in range(4):
        check([x[c] for x in l])
    check([l[i][i] for i in range(4)])
    check([l[i][3 - i] for i in range(4)])

    r = ""
    if win_o:
        r = "O won"
    elif win_x:
        r = "X won"
    elif finished:
        r = "Draw"
    else:
        r = "Game has not completed"

    print "Case #%d: %s" % (t + 1, r)
