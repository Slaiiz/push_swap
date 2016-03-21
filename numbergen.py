#!/usr/bin/python

# HOW TO USE:
# ./push_swap $(python numbergen.py)
# OR: (under certain circumstances)
# ./push_swap $(./numbergen.py)
#

from sys import stdout
import random

n = 100
data = []
random.seed();
while n:
	data.append(random.randint(-65536, 65535));
	n -= 1
i = iter(data)
while True:
	try:
		stdout.write(str(i.next()))
	except:
		break
	stdout.write(" ")
