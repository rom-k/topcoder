#!/usr/bin/python
# -*- coding: utf-8 -*-
# Copyleft rom.cpp@gmail.com

import xml.etree.ElementTree
import re

tree = xml.etree.ElementTree.parse('person_name.xml')
root = tree.getroot()

for tr in root:
    tds = [re.sub("\t", "", x.text) for x in list(tr)]
    tds[1] = re.sub(u"　", ",", tds[1])
    print ",".join(tds)

