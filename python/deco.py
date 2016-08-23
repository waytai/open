#########################################################################
#-*- coding:utf-8 -*-
# File Name: deco.py
#########################################################################
#!/bin/python
def hello(fn):
    def wrapper():
        print "hello, %s" %fn.__name__
        fn()
        print "goodbye, %s" %fn.__name__
    return wrapper

@hello
def foo():
    print "just for test"

foo()
