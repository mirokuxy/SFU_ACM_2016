import sys
import math

def get_mid(ax, ay, bx, by, p):
  x = p * bx + (1-p) * ax
  y = p * by + (1-p) * ay
  return x,y

def cross_point(ab, cd):
  a,b = ab
  c,d = cd
  rel_tol = 1e-09
  if abs(c-d) <= (rel_tol):
    p = float(c)
  elif c < d:
    bot = float(c) / (d-c)  + a
    top = float(1-d) / (d-c) + (1-b)
    p = bot / (top+bot)
    #print "({0},{1}) ({2}, {3}) :  bot({4}) top({5}) p({6})".format(a,b,c,d, bot, top, p)
  else:
    bot = float(d) / (c-d)  + (1-a)
    top = float(1-c) / (c-d) + b
    p = bot / (top+bot)
    #print "({0},{1}) ({2}, {3}) :  bot({4}) top({5}) p({6})".format(a,b,c,d, bot, top, p)

  return get_mid(a, 0, b, 1, p)

def get_area(a, b, c):
  ax, ay = a
  bx, by = b
  cx, cy = c

  return math.fabs( (ax*(by-cy) + bx*(cy-ay) + cx*(ay-by)) /2 )

n = int(raw_input().strip())
while n != 0:
  a = map(float, raw_input().strip().split())
  b = map(float, raw_input().strip().split())
  c = map(float, raw_input().strip().split())
  d = map(float, raw_input().strip().split())

  ab = zip(a,b)
  ab = [(0,0)] + ab + [(1,1)]

  cd = zip(c,d)
  cd = [(0,0)] + cd + [(1,1)]

  #print ab
  #print cd

  max_area = 0.0

  for i in xrange(len(ab) -1):
    ab1 = ab[i]
    ab2 = ab[i+1]

    #_range = xrange(len(c) -1)
    #if i == 0 :
    # _range = xrange(1, len(c) -2)


    for j in xrange(len(cd) -1):
      cd1 = cd[j]
      cd2 = cd[j+1]

      p1 = cross_point(ab1, cd1)
      p2 = cross_point(ab2, cd1)
      p3 = cross_point(ab1, cd2)
      p4 = cross_point(ab2, cd2)

      area = get_area(p1, p2, p4) + get_area(p1, p3, p4)
      #print ab1, ab2, cd1, cd2
      #print p1, p2, p3, p4
      #print area

      max_area = max(max_area, area)

  print "{0:.6f}".format(max_area)

  n = int(raw_input().strip())