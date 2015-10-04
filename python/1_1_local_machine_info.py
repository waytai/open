#########################################################################
#-*- coding:utf-8 -*-
# File Name: 1_1_local_machine_info.py
# Author: wayne
# mail: @163.com
# Created Time: 2015年10月04日 星期日 20时40分37秒
#########################################################################
#!/bin/python

import socket
def print_machine_info():
    host_name = socket.gethostname()
    print host_name
    ip_address = socket.gethostbyname(host_name)
    print ip_address

if __name__ == "__main__":
    print_machine_info()

