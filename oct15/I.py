import sys
import math


class State(object):
	def __init__(self, sum_cost, sum_perf, x, is_child):
		self.sum_cost = sum_cost
		self.sum_perf = sum_perf
		self.x = x
		self.is_child = is_child

def FindMax(cost, perf, adjancy, n):
	states = []
	max_val = 0

	for i in xrange(1, n+1):
		states.append(State(0, 0, i, False))

	start = 0
	end = n

	while start < end:
		state = states[start]
		start += 1

		x = state.x
		sum_cost = state.sum_cost
		sum_perf = state.sum_perf
		is_child = state.is_child

		sum_perf += perf[x]
		if is_child:
			sum_cost += float(cost[x]) /2
		else:
			sum_cost += cost[x]

		max_val = max(max_val, float(sum_perf) / float(sum_cost))

		children = adjancy[x]
		for child in children:
			states.append(State(sum_cost, sum_perf, child, True))
			end += 1

	return max_val


def GetMax(cost, perf, adjancy, sum_cost, sum_perf, x, is_child):
	if is_child:
		sum_cost += float(cost[x]) /2
	else:
		sum_cost += cost[x]
	
	sum_perf += perf[x]

	res = float(sum_perf) / float(sum_cost)

	children = adjancy[x]
	for child in children:
		temp = GetMax(cost, perf, adjancy, sum_cost, sum_perf, child, True)
		res = max(res, temp)

	return res


n, e, p = map(int, raw_input().strip().split())

while n != 0:
	cost = [0]
	perf = [0]
	adjancy = [ [] for i in xrange(n+1) ]
	
	for i in xrange(1, n+1):
		_c, _p, _n = map(int, raw_input().strip().split())
		cost.append(_c)
		perf.append(_p)
		if _n != 0:
			adjancy[_n].append(i)

	#max_val = 0
	#for i in xrange(1, n+1):
	#	val = GetMax(cost, perf, adjancy, 0, 0, i, False)
	#	max_val = max(max_val, val)

	#print cost
	#print perf
	#print adjancy
	#print max_val

	max_val = FindMax(cost, perf, adjancy, n)

	time = math.log(float(p) / float(max_val * e)) / float(max_val)
	time = int(round(time) + 0.1)

	print time

	n, e, p = map(int, raw_input().strip().split())


