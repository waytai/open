#########################################################################
# -*- coding:utf-8 -*- 
# File Name: borg.py
# Author: wayne
# mail: @163.com
# Created Time: 2015/9/2 16:24:02
#########################################################################
#!/bin/python
class Borg:
    __shared_state = {}

    def __init__(self):
        self.__dict__ = self.__shared_state

    def __str__(self):
        return self.state

    def __repr__(self):
        return self.state

class YourBorg(Borg):
    pass

if __name__ == '__main__':
    rm1 = Borg()
    rm2 = Borg()

    rm1.state = 'Idle'
    rm2.state = 'Running'

    print('rm1:', rm1)
    print('rm2:', rm2)

    print "-"*30
    rm2.state = 'Zombie'

    print('rm1:', rm1)
    print('rm2:', rm2)

    print('rm1 id:', id(rm1))
    print('rm2 id:', id(rm2))

    print "-"*30

    rm3 = YourBorg()

    print('rm1:', rm1)
    print('rm2:', rm2)
    print('rm3:', rm3)

