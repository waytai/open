#########################################################################
# -*- coding:utf-8 -*- 
# File Name: met.py
# Author: wayne
# mail: @163.com
# Created Time: 2015/8/27 10:37:44
#########################################################################
#!/bin/python
import time
from functools import wraps

def timethis(func):
    '''
    Decorator that reports the execution time.
    '''
    @wraps(func)
    def wrapper(*args, **kwargs):
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        print(func.__name__, end-start)
        return result
    return wrapper


@timethis
def countdown(n):
    '''
    Counts down
    '''
    while n > 0:
        n -= 1

countdown(10000000)
