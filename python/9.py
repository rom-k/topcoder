#!/usr/bin/python
# -*- coding: utf-8 -*-

def ask_ok(prompt, retries=4, complaint='Yes or no, please!'):
    while True:
        ok = raw_input(prompt)
        if ok in ('y', 'ye', 'yes'):
            return True
        if ok in ('n', 'no', 'nop', 'nope'):
            return False
        retries = retries - 1
        if retries < 0:
            raise IOError('refusenik user')
        print complaint

# 必須の引数のみ与える:
ask_ok('Do you really want to quit?')

# 一つのオプション引数を与える:
ask_ok('OK to overwrte the file?', 2)

# 全ての引数を与える:
ask_ok('OK to overwrte the file?', 2, 'Come on, only yes or no!')

