#!/usr/bin/python
# -*- coding: utf-8 -*-

"""This file contains PasswordGenerator class which generate random password.

By default, generate a random password which satisfy constraints below.
- May include upper and lower case letters, numbers, and special characters
  (!"#$%'()).
- Must use at least 3 kinds of characters (upper/lower/digit/special).
- Length must equal or longer than 12, and equal or shorter than 16.

Developed and tested on python version 2.7.3

Copyleft rom.cpp@gmail.com
"""

import string


def merge_set(set_list):
    """Merge list of sets and return a set.
    """
    merged_set = set()
    for s in set_list:
        merged_set |= s
    return merged_set


class PasswordGenerator(object):
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
        """Constructor for PasswordGenerator.
        """
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
        """Generate new password.
        """
        char_count = len(self.all_chars)

        while 1:
            pass


if __name__ == '__main__':
    chars_list = []
    chars_list.append(string.ascii_lowercase)
    chars_list.append(string.ascii_uppercase)
    chars_list.append(string.digits)
    chars_list.append("""!"#$%&'()""")

    passgen = PasswordGenerator(chars_list=chars_list,
                            kinds_at_least=3,
                            min_length=12,
                            max_length=16)

    print passgen.generate()
