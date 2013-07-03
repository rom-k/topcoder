#!/usr/bin/python
# -*- coding: utf-8 -*-
# developed and tested on python version 2.7.3

"""This file contains PassGenerator class which generate random password.

By default, generate a random password which satisfy constraints below.
- May include upper and lower case letters, numbers, and special characters
  (!"#$%'()).
- Must use at least 3 kinds of characters (upper/lower/digit/special).
- Length must equal or longer than 12, and equal or shorter than 16.

Copyleft rom.cpp@gmail.com
"""

import string


def merge_set(set_list):
    merged_set = set()
    for s in set_list:
        merged_set |= s
    return merged_set


class PassGenerator(object):
    """Class to generate password string.

    Attributes:
        chars_list: String list with usable charactors.
        kinds_at_least: Number of lists whose charactor must be included in
            the password at least.
        min_length: Minimum password length.
        max_length: Maximum password length.
    """
    def __init__(self, chars_list, kinds_at_least=1, min_length=1,
                 max_length=16):

        if max_length < min_length:
            raise ValueError("min_length is larger than max_length")
        if len(chars_list) < kinds_at_least:
            raise ValueError("kinds_at_least is larger than the size of" +
                             " chars_list.")

        self.char_set_list = [set(x) for x in chars_list]
        self.all_chars = sorted(list(merge_set(self.char_set_list)))

        self.kinds_at_least = kinds_at_least
        self.min_length = min_length
        self.max_length = max_length

    def generate(self):
        return "hoge"


if __name__ == '__main__':
    chars_list = []
    chars_list.append(string.ascii_lowercase)
    chars_list.append(string.ascii_uppercase)
    chars_list.append(string.digits)
    chars_list.append("""!"#$%&'()""")

    kinds_at_least = 3

    min_length = 12
    max_length = 16

    passgen = PassGenerator(chars_list = chars_list,
                            kinds_at_least = kinds_at_least,
                            min_length = min_length,
                            max_length = max_length)

    print passgen.generate()

