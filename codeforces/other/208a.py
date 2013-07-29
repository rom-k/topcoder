#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import re

s = sys.stdin.readline().strip()

print re.sub(r"(WUB){1,}", " ", s).strip()
