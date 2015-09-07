class Student(object):
    def __init__(self, name):
        self.name = name
    def __repr__(self):
        print "8"*20
        return 'Student object (name: %s)' % self.name
    def __str__(self):
        print "*"*20
        return 'Student object str (name: %s)' % self.name

print Student('liu')
