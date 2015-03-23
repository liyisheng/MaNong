#!/usr/bin/python

inputFile = open('text.txt', 'w')
	
import random
for i in range(10):
	s = str(random.randint(1,100)) + '\n'
	inputFile.write(s)
inputFile.close()

x = []
outputFile = open('text.txt', 'r')
x = [int(line) for line in outputFile]

print x
for i in x:
	if i%7 is 0:
		print i

		
