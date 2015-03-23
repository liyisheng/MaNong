#########################################################################
# File Name: printMax.py
# Author: liyisheng
# mail: liyishengchn@gmail.com
# Created Time: Sat 14 Mar 2015 05:34:01 PM CST
#########################################################################
#!/bin/python
def printMax(x, y):
	"""Print the maximum of two numbers.

	The two values must be integers."""
	x = int(x)
	y = int(y)

	if x > y:
		print x,'is maximum'
	else:
		print y,'is maximum'

help(printMax)
printMax(3,5)
print printMax.__doc__
	
