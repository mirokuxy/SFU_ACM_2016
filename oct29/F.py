# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys
import math


def isPrim(n):
  for i in xrange(2, int(math.sqrt(n)) ):
    if n%i == 0:
      return False
  return True

def isCarm(n):
  for i in xrange(2, n):
    if pow(i, n, n) != i:
      return False
  return True


for line in sys.stdin:
  n = int(line.strip())
  if n == 0:
    break

  if (not isPrim(n)) and isCarm(n):
    print "The number {0} is a Carmichael number.".format(n)
  else:
    print "{0} is normal.".format(n)
