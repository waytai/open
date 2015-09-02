#########################################################################
#-*- coding:utf-8 -*-
# File Name: uname.py
# Author: wayne
# mail: @163.com
# Created Time: 2015年09月01日 星期二 11时00分56秒
#########################################################################
#!/bin/python
import os
import pprint
print os.name
print os.uname()
pprint.pprint(os.environ)
print os.getenv('PATH')
