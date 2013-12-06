#!/usr/bin/python
# -*- coding: utf-8 -*-

"""This file contains get_max_combination subroutineh which returns one sum
value of the two values in the provided list, and the sum value is the
largest value which not greater than the limit value provided.

Developed and tested on python version 2.7.3

Copyleft rom.cpp@gmail.com
"""

import sys
from bisect import bisect


def get_max_combination(limit_value, value_list):
    """Subroutine to get max combination.

    Attributes:
        limit_value: Limit value for the output sum value.
        value_list:  Value list.
    """

    return_value = 0
    max_index = len(value_list) - 1

    for i in range(len(value_list)):

        value_i = value_list[i]
        rest_value = limit_value - value_i

        if rest_value < value_i:
            break

        index = bisect(value_list, rest_value, i + 1, max_index + 1) - 1
        max_index = index
        if max_index <= i:
            break

        return_value = max(return_value, value_i + value_list[index])

    return return_value


if __name__ == '__main__':

    value_count, query_count = map(int, sys.stdin.readline().strip().split())

    value_list = []
    for i in range(value_count):
        value_list.append(int(sys.stdin.readline().strip()))
    value_list.sort()

    for i in range(query_count):
        query = int(sys.stdin.readline().strip())
        answer = get_max_combination(query, value_list)
        print answer
