#如何在一个函数内部修改全局变量
a = 200


def fn():
    global a
    a = 202


fn()
print(a)
