import sys

ranks = [0] * 26

for i in xrange(0, 11):
	ranks[i] = 5
for i in xrange(11, 16):
	ranks[i] = 4
for i in xrange(16, 21):
	ranks[i] = 3
for i in xrange(21, 26):
	ranks[i] = 2


#for i in xrange(1, 26):
#	print ranks[i], 

sequence = raw_input().strip()

res = 25
star = 0
wins = 0

for x in sequence:
	if x == 'W':
		wins += 1
		star += 1
		if res >= 6 and res <= 25 and wins >= 3:
			star += 1
		if res >= 1 and  star > ranks[res]:
			star -= ranks[res]
			res -= 1
			
	else:
		wins = 0
		if 1 <= res and res <= 20 and (not (res == 20 and star == 0)):
			if star == 0:
				res += 1
				star = ranks[res] -1
			else:
				star -= 1

if res >= 1:
	print res
else:
	print "Legend"

