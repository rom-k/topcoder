#!/usr/bin/python
# -*- coding: utf-8 -*-

def fib(n):    # n までのフィボナッチ級数を出力する
    """Print a Fibonacci series up to n."""
    a, b = 0, 1
    while a < n:
        print a,
        a, b = b, a+b

def fib2(n): #  n までのフィボナッチ級数を返す
    """Return a list containing the Fibonacci series up to n."""
    result = []
    a, b = 0, 1
    while a < n:
        result.append(a)
        a, b = b, a+b
    return result

# 今しがた定義した関数を呼び出す:
#fib(2000)
fib(int(raw_input("Enter integer : ")))

