#########################################################################
# -*- coding:utf-8 -*- 
# File Name: re.py
# Author: wayne
# mail: @163.com
# Created Time: 2015/8/26 16:36:51
#########################################################################
#!/bin/python
class Reverse:
    """Iterator for looping over a sequence backwards."""
    def __init__(self, data):
        self.data = data
        self.index = len(data)
    def __iter__(self):
        return self
    def next(self):
        if self.index == 0:
            raise StopIteration
        self.index = self.index - 1
        return self.data[self.index]


rev = Reverse('spam')
for x in iter(rev):
    print x
