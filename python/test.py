#########################################################################
#-*- coding:utf-8 -*-
# File Name: test.py
# Author: wayne
# mail: @163.com
# Created Time: 2015年10月12日 星期一 22时36分58秒
#########################################################################
#!/bin/python

def add(x, y, f):
    return f(x) + f(y)

print add(10, -10, abs)

f = lambda x, y, f: f(x) + f(y)

print f(10, -10, abs)
