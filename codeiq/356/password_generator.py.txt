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
import random


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

    def generate_random_length(self):
        """Generate length of password with a fair to password space.
        """
        char_count = len(self.all_chars)
        all_pass_count = ((char_count ** (self.max_length + 1) -
                           char_count ** self.min_length) /
                         (char_count - 1))
        length_picker = int(random.random() * all_pass_count)

        for length in range(self.max_length, self.min_length - 1, -1):
            length_picker -= char_count ** length
            if length_picker < 0:
                return length

    def generate_random_char(self):
        """Generate a random char from all_chars.
        """
        char_count = len(self.all_chars)
        char_picker = int(random.random() * char_count)
        return self.all_chars[char_picker]

    def verify_password(self, passwd):
        """Verify password and return true if cleared test.
        """
        kinds_count = len(self.char_set_list)
        using_kinds = [0] * kinds_count

        for char in passwd:
            for i in range(kinds_count):
                if char in self.char_set_list[i]:
                    using_kinds[i] += 1

        kinds_count_used = 0
        for i in range(kinds_count):
            if using_kinds[i] > 0:
                kinds_count_used += 1

        return kinds_count_used >= self.kinds_at_least

    def generate(self):
        """Generate new password.
        """
        while 1:
            length = self.generate_random_length()
            new_pass = ""
            for i in range(length):
                new_pass += self.generate_random_char()

            if self.verify_password(new_pass):
                return new_pass


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
