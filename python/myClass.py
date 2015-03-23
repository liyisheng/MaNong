#!/usr/bin/env python

class MyClass:
	def __init__(self, name):
		self.name = name
	def show(self):
		print 'Name is', self.name

MyClass('Jack').show()

class ChildClass(MyClass):
	def show(self):
		print "I'am child", self.name

ChildClass('Tom').show()



class C:
	count = 0 #number of times  C.__init__ called
	def __init__(self):
		C.count += 1
		self.instanceCount = C.count
	def getCount(self):
		return C.count
	def getInstanceCount(self):
		return self.instanceCount

def test():
	c1 = C()
	c2 = C()
	print "Instance created:", C.count
	print "c1 count:", c1.getInstanceCount()
	print "c2 count:", c2.getInstanceCount()

test()
