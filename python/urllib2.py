#!/usr/bin/python
# -*- coding: utf-8 -*-

import urllib2

for line in urllib2.urlopen('http://tycho.usno.navy.mil/cgi-bin/timer.pl'):
    if 'EST' in line or 'EDT' in line:      # EST(東部標準時)を見る
        print line
