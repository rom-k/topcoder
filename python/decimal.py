#!/usr/bin/python
# -*- coding: utf-8 -*-

from decimal import *

print Decimal('0.70') * Decimal('1.05')
print .70 * 1.05

print Decimal('1.00') % Decimal('.10')
print 1.00 % 0.10

print sum([Decimal('0.1')]*10) == Decimal('1.0')
print sum([0.1]*10) == 1.0
