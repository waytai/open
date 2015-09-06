#########################################################################
# -*- coding:utf-8 -*- 
# File Name: deq.py
# Author: wayne
# mail: @163.com
# Created Time: 2015年09月06日 星期日 22时14分11秒
#########################################################################
#!/bin/python
import collections
q_one = collections.deque()
q_one.append(1)
q_one.append(1)
q_one.appendleft(2)
q_one.extend([3,4])
q_one.extendleft([5,6])
print q_one
