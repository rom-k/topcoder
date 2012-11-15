#!/usr/bin/python
# -*- coding: utf-8 -*-

import zlib

s = 'witch which has which witches wrist watch'
print len(s)

t = zlib.compress(s)
print len(t)

print zlib.decompress(t)
print zlib.crc32(s)
