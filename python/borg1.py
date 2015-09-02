#########################################################################
# -*- coding:utf-8 -*- 
# File Name: borg1.py
# Author: wayne
# mail: @163.com
# Created Time: 2015/9/2 16:40:41
#########################################################################
#!/bin/python
class Config(object):
    _we_are_one = {}
    _myvalue = ""

    def __new__(cls, *p, **k):
        self = object.__new__(cls, *p, **k)
        self.__dict__ = cls._we_are_one
        return self

    def myvalue(self, value=None):
        if value:
            self._myvalue = value
        return self._myvalue

if __name__ == '__main__':
    conf = Config()
    conf.myvalue("Hello")
    conf2 = Config()
    print conf2.myvalue()
