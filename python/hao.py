#########################################################################
# -*- coding:utf-8 -*- 
# File Name: hao.py
# Author: wayne
# mail: @163.com
# Created Time: 2015/8/31 9:54:54
#########################################################################
#!/bin/python
def choose_class(name):
     if name == 'foo':
         class Foo(object):
             pass
         return Foo     
     else:
         class Bar(object):
             pass
         return Bar

MyClass = choose_class('foo')
print MyClass              


class ObjectCreator(object):
    pass
print type(ObjectCreator)
print type(ObjectCreator())



#以下两个等同
class Foo(object):
    bar = True
print Foo

Foo = type('Foo', (), {'bar':True})
print Foo

#以下两个等同
class FooChild(Foo):
    pass

print FooChild

FooChild = type('FooChild', (Foo,) ,{})


print FooChild
