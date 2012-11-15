#!/usr/bin/python
# -*- coding: utf-8 -*-

from datetime import date

now = date.today()
print now

print now.strftime("%m-%d-%y. %d %b %Y is a %A on the %d day of %B")

birthday = date(1964, 7, 31)
age = now - birthday
print age.days
