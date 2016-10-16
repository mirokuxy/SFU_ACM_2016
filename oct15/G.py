import sys


def countC(c, n):
	res = 1
	for i in xrange(c):
		res *= n - i
	for i in xrange(1, c+1):
		res /= i
	return res

def count3(x, n):
	res = 0
	while x <= n:
		res += countC(x, n)
		x += 3

	return res 

for line in sys.stdin:
	n = int(line.strip())

	b = "{0:b}".format(n)
	L = len(b)
	pos = [ L - i for i in xrange(L) if b[i] == "1" ]
	#print pos

	height = 0

	for i in xrange(len(pos)):
		c3 = (3 - i % 3) % 3
		temp = count3( c3 , pos[i]-1)
		height += temp
		#print "(", c3, pos[i]-1, ")", ":", temp

	if len(pos) % 3 == 0:
		height += 1

	height -= 1

	#print height
	print "Day {0}: Level = {1}".format(n, height)

	


