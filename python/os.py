#!/usr/bin/python
# -*- coding: utf-8 -*-

import os

#os.system('time 0:02')
print os.getcwd()
os.chdir('/work')
print os.getcwd()

print dir(os)
help(os)
