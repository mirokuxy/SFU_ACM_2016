import sys
import math

class Point(object):
  def __init__(self, x, y):
    self.x = x
    self.y = y



def dist(p1, p2):
  return math.sqrt((p1.x - p2.x) **2 + (p1.y - p2.y) ** 2)

def diff(p1, p2):
  return Point(p2.x - p1.x, p2.y - p1.y)


data = []
for line in sys.stdin:
  data.append(line)
data = ' '.join(data)

data = map(int, data.strip().split())

n = data[0]
a = data[1] - 1
b = data[2] - 1


points = []

for i in xrange(n):
  x = data[i*2 + 3]
  y = data[i*2 + 3 +1]
  points.append(Point(x,y))


def greaterPi(x):
  return x > math.pi
def lesserPi(x):
  return x < math.pi

def isConvex(p1, p2, p3, inRange):
  old = diff(p2, p1)
  new = diff(p2, p3)
  angle = math.atan2(old.y, old.x) - math.atan2(new.y, new.x)
  if angle < 0:
    angle += 2 * math.pi

  return inRange(angle)

def calc(start, end, tot, dir, inRange):
  que = []

  now = start
  que.append(points[now])

  while now != end:
    now = (now + dir + tot) % tot

    p = points[now]
    while len(que) >= 2 and (not isConvex(que[-2], que[-1], p, inRange)):
      que.pop()
    que.append(p)

  tot_dist = 0
  for i in xrange(1, len(que)):
    tot_dist += dist(que[i-1], que[i])
  return tot_dist

def isClockwise(points):
  res = 0

  L = len(points)
  for i in xrange(L):
    j = (i+1) % L
    area = (points[j].x - points[i].x) * (points[j].y + points[i].y)
    res += area

  return res > 0

max_dist = 0

if not isClockwise(points):
  d = calc(a, b, n, 1, lesserPi)
  max_dist = max(max_dist, d)
  d = calc(a, b, n, -1, greaterPi)
  max_dist = max(max_dist, d)
else:
  d = calc(a, b, n, -1, lesserPi)
  max_dist = max(max_dist, d)
  d = calc(a, b, n, 1, greaterPi)
  max_dist = max(max_dist, d)

print max_dist
