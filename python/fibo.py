#!/usr/bin/python
# -*- coding: utf-8 -*-


# フィボナッチ数列モジュール

def fib(n):
    # nまでのフィボナッチ級数を出力
    a, b = 0, 1
    while b < n:
        print b,
        a, b = b, a + b


def fib2(n):
    # nまでのフィボナッチ級数を返す
    result = []
    a, b = 0, 1
    while b < n:
        result.append(b)
        a, b = b, a + b
    return result


if __name__ == "__main__":
    import sys
    fib(int(sys.argv[1]))
