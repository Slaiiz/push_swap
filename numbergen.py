# HOW TO USE:
# ./push_swap $(python numbergen.py)

from sys import stdout
import random

n = 15
data = []
random.seed();
while n:
	data.append(random.randint(-2000, 2000));
	n -= 1
i = iter(data)
while True:
	try:
		stdout.write(str(i.next()))
	except:
		break
	stdout.write(" ")
