#########################################################################
# -*- coding:utf-8 -*- 
# File Name: orderdict.py
# Author: wayne
# mail: @163.com
# Created Time: 2015年09月06日 星期日 22时24分39秒
#########################################################################
#!/bin/python
import collections
m = collections.OrderedDict((str(x),x) for x in xrange(10))
print m
print ' '.join(m.keys())
