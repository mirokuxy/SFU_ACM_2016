import sys


good = [1,2,3,3,4,10]
evil = [1,2,2,2,3,5,11]

n = int(raw_input().strip())

for i in xrange(1, n+1):
	good_count = map(int, raw_input().strip().split())
	evil_count = map(int, raw_input().strip().split())

	good_point = sum( good[j] * good_count[j] for j in xrange(len(good_count)) )
	evil_point = sum( evil[j] * evil_count[j] for j in xrange(len(evil_count)) )


	if good_point > evil_point:
		print "Battle " + str(i) + ":",
		print "Good triumphs over Evil"
	elif good_point < evil_point:
		print "Battle " + str(i) + ":",
		print "Evil eradicates all trace of Good"
	else:
		print "Battle " + str(i) + ":",
		print "No victor on this battle field"

