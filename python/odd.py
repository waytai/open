#########################################################################
#-*- coding:utf-8 -*-
# File Name: odd.py
#########################################################################
#!/bin/python

def is_odd(n):
    return n % 2 == 1

odd = lambda n : n %2 == 1

print list(filter(is_odd, [1,2,3,4,5,6,7,8,9]))
print list(filter(odd, [1,2,3,4,5,6,7,8,9]))
print odd(4)
