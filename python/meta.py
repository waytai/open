#########################################################################
# -*- coding:utf-8 -*- 
# File Name: meta.py
# Author: wayne
# mail: @163.com
# Created Time: 2015/8/28 13:40:14
#########################################################################
#!/bin/python
VERION_METHODS='version_methods'

class VersionMethod(object):
    def __init__(self, version, func):
        self.version = version
        self.func = func


class MetaClass(type):
    def __new__(cls, name, bases, cls_dict):
        for base in bases:
            version_methods = getattr(base, VERION_METHODS, None)
            if version_methods:
                cls_dict[VERION_METHODS] = version_methods
                delattr(base, VERION_METHODS)

        return super(MetaClass, cls).__new__(cls, name, bases, cls_dict)


class Base(object):
    __metaclass__ = MetaClass

    def __getattribute__(self, name):

        def version_select(*args, **kwargs):
            if len(args) > 0:
                version = args[0]['version']
            else:
                version = kwargs['req']['version']
            for version_func in self.version_methods.get(name, None):
                if version_func.version == version:
                    return version_func.func(self, *args, **kwargs)
            raise AttributeError

        try:
            version_methods = object.__getattribute__(self, VERION_METHODS)
        except AttributeError:
            return object.__getattribute__(self, name)

        if version_methods and \
                name in version_methods:
            return version_select
        return object.__getattribute__(self, name)


    @classmethod
    def version(cls, version):
        def wrapper(func):
            name = func.func_name
            version_methods = getattr(cls, VERION_METHODS, {})
            if not version_methods:
                setattr(cls, VERION_METHODS, version_methods)

            methods = version_methods.get(name, [])
            if not methods:
                version_methods[name] = methods
            methods.append(VersionMethod(version, func))

            return func
        return wrapper


class SubClass(Base):

    @Base.version("1.0")
    def foo(self, req):
        print "in SubClass 1.0 version: %s" % req

    @Base.version("2.0")
    def foo(self, req):
        print "in SubClass 2.0 version: %s" % req

class SubClass2(Base):

    @Base.version("1.0")
    def foo(self, req):
        print "in SubClass2 1.0 version: %s" % req

    @Base.version("2.0")
    def foo(self, req):
        print "in SubClass2 2.0 version: %s" % req




SubClass().foo({"version": "1.0"})
SubClass().foo({"version": "2.0"})

SubClass2().foo({"version": "1.0"})
SubClass2().foo({"version": "2.0"})

# Output
# in SubClass 1.0 version: {'version': '1.0'}
# in SubClass 2.0 version: {'version': '2.0'}
# in SubClass2 1.0 version: {'version': '1.0'}
# in SubClass2 2.0 version: {'version': '2.0'}
