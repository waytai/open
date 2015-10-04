#########################################################################
#-*- coding:utf-8 -*-
# File Name: 1_2_remote_machine_info.py
# Author: wayne
# mail: @163.com
# Created Time: 2015年10月04日 星期日 20时34分17秒
#########################################################################
#!/bin/python
import socket
def get_remote_machine_info():
    remote_host = "www.baidu.com"
    try:
        print "IP Address is %s\n" %socket.gethostbyname(remote_host)
    except socket.error, err_msg:
        print "%sm,%s" %(remote_host, err_msg)


if __name__ == "__main__":
    get_remote_machine_info()
