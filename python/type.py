#########################################################################
# -*- coding:utf-8 -*- 
# File Name: hao.py
# Author: wayne
# mail: @163.com
# Created Time: 2015/8/31 9:54:54
#########################################################################
#!/bin/python
class Meta(type):
    def __new__(cls, name, bases, attrs):
        output = attrs['output']
        attrs['output'] = lambda self, x: output(self, 'python')
        return type.__new__(cls, name, bases, attrs)

class Base(dict):
    __metaclass__ = Meta
    def output(self, o): print 'hello, %s' % o
b = Base()
b.output('world')

print "-"*20
A = type('A', (object,), {'b': 1})
a = A()
print A, a.b

print "-"*20
def f(name, bases, attrs):
    attrs['c'] = 2
    return type(name, bases, attrs)

A = f('A', (object,), {'b': 1})
a = A()
print A, a.b, a.c

print "-"*20
def f(name, bases, attrs):
    attrs['c'] = 2
    return type(name, bases, attrs)

class A(object):
    __metaclass__ = f
    b = 1

a = A()
print A, a.b, a.c 
