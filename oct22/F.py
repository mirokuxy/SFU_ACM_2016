import sys
from random import randint

n, p = map(int, raw_input().strip().split())



def calcF(x, n, p):
	res = 1.0
	res = 1.0 * p

	up = []
	for i in xrange(n-p+2, n+1):
		up.append(i)

	down = []
	for i in xrange(x+n, x+n-p, -1):
		if len(up)>0 and up[-1] == i:
			up.pop()
		else:
			down.append(i)

	up.append(x)

	for i in xrange(len(up)):
		res *= float(up[i])
		res /= float(down[i])

	"""
	for i in up:
		res *= float(i)
	for i in down:
		res /= float(i)
	"""

	"""
	prod1 = 1
	for i in up:
		prod1 *= i

	prod2 = 1
	for i in down:
		prod2 *= i

	res = res * float(prod1) / float(prod2)
	"""
	return res

#print "x:", x

"""
for n in xrange(2, 1000000):
	for i in  xrange(100):
		p = randint(2, n)

		x = (n-p+1) / (p-1)
		f1 = calcF(x, n, p)
		f2 = calcF(x+1, n, p)

		#print "f1: ", f1
		#print "f2: ", f2

		if f1 > f2:
			res = f1
		else:
			res = f2
		print res
"""

x = (n-p+1) / (p-1)
f1 = calcF(x, n, p)
f2 = calcF(x+1, n, p)

#print "f1: ", f1
#print "f2: ", f2

if f1 > f2:
	res = f1
else:
	res = f2
print res
