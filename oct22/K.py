import sys
import math
from collections import deque

class Point(object):
	def __init__(self, x,y):
		self.x = x
		self.y = y
	def __str__(self):
		return "({0},{1})".format(self.x, self.y)

class Segment(object):
	def __init__(self, a, b):
		self.a = a
		self.b = b
	def length(self):
		a,b = self.a, self.b
		return math.sqrt( (b.x - a.x) **2 + (b.y - a.y) ** 2 )
	def diff(self):
		a,b = self.a, self.b
		return math.fabs(a.x - b.x), math.fabs(a.y - b.y)
	def divide(self, p):
		a,b = self.a, self.b
		mid = Point( p*b.x + (1-p)*a.x, p*b.y + (1-p)*a.y )
		return Segment(a, mid), Segment(mid, b)
	def __str__(self):
		return "[{0}, {1}]".format(self.a, self.b)

def segEqualLen(Ln, Lm):
	dnx, dny = Ln.diff()
	dmx, dmy = Lm.diff()

	if dnx == dmx and dny == dmy:
		return True
	elif dnx == dmy and dny == dmx:
		return True
	else:
		return False


pointN = []
pointM = []

lineN = deque([])
lineM = deque([])

n = int(raw_input().strip())
for i in xrange(n):
	x,y = map(int, raw_input().strip().split())
	pointN.append(Point(x,y))

m = int(raw_input().strip())
for i in xrange(m):
	x,y = map(int, raw_input().strip().split())
	pointM.append(Point(x,y))

for i in xrange(1, len(pointN)):
	lineN.append( Segment(pointN[i-1], pointN[i]) )
for i in xrange(1, len(pointM)):
	lineM.append( Segment(pointM[i-1], pointM[i]) )

min_dist = 20000000

while len(lineN)>0 and len(lineM)>0:
	segN = lineN.popleft()
	segM = lineM.popleft()

	lenN = segN.length()
	lenM = segM.length()

	if not segEqualLen(segN, segM):
		if lenN < lenM:
			p = float(lenN) / float(lenM)
			segM1, segM2 = segM.divide(p)
			#print "lenN {0}, lenM {1}, p {2}".format(lenN, lenM, p)
			#print "segM1 {0}, segM2 {1}".format(segM1, segM2)
			segM = segM1
			lineM.appendleft(segM2)
		else:
			p = float(lenM) / float(lenN)
			segN1, segN2 = segN.divide(p)
			segN = segN1
			lineN.appendleft(segN2)

	Ax = segN.a.x - segM.a.x
	Bx = segN.b.x - segM.b.x
	Ay = segN.a.y - segM.a.y
	By = segN.b.y - segM.b.y

	a = (Ax - Bx) **2 + (Ay - By) ** 2
	b = 2 * (Ax - Bx) * Bx + 2 * (Ay - By) * By
	c = Bx ** 2 + By ** 2

	if a != 0:
		mid = float(-b) / 2 / a

		if mid > 1:
			min_len = (a + b + c)
		elif mid < 0:
			min_len = (c)
		else:
			min_len = (c - float(b*b)/4/a)
	else:
		if b == 0:
			min_len = c
		elif b > 0:
			min_len = c
		else:
			min_len = a + b + c

	min_len = math.sqrt(min_len)

	#print "{0} - {1} : {2}".format(segN, segM, min_len)

	min_dist = min(min_dist, min_len)

print min_dist
