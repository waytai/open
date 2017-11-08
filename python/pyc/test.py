#########################################################################
#-*- coding:utf-8 -*-
# File Name: test.py
#########################################################################
#!/bin/python
import ctypes
ll = ctypes.cdll.LoadLibrary
lib = ll("./test.so")
lib.test()
print '***finish***'
