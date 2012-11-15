#!/usr/bin/python
# -*- coding: utf-8 -*-


class MyClass2:
    """ My class 2.
    """

    j = 21

    def __init__(self, i=31):
        self.set_i(i)

    def get_i(self):
        return self.i

    def get_j(self):
        return self.j

    def set_i(self, i):
        self.i = i

    def set_j(self, j):
        self.j = j

x = MyClass2(11)
y = MyClass2()
z = MyClass2()

print x.get_i()  # => 11
print y.get_j()  # => 21
print z.get_i()  # => 31

x.set_i(13)
y.set_j(23)
z.set_i(33)

print x.get_i()  # => 13
print y.get_j()  # => 23
print z.get_i()  # => 33
