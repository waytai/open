#########################################################################
#-*- coding:utf-8 -*-
# File Name: test.py
#########################################################################
#!/bin/python
f = lambda x: 'test' if 'dev' or 'seal' or 'test' in x else 'main'
print f('test/for')
print f('seal/for')

tf = lambda y: 'test'
print tf('sss')
