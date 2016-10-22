import sys

def LIS(l):
	DP = [1] * ( len(l) + 1)

	for i in xrange(1, len(l)):
		max_val = 0
		for j in xrange(i):
			if l[j] < l[i]:
				max_val = max(max_val, DP[j])

		DP[i] = max_val + 1

	max_val = 0
	for i in xrange(0, len(l)):
		max_val = max(max_val, DP[i])

	return max_val


class Suit(object):
	def __init__(self, index, order):
		self.index = index
		self.order = order
	def getVal(self, v):
		if self.order == False:
			v = 16 - v
		return self.index * 100 + v


class Card(object):
	def __init__(self, s):
		if '2' <= s[0] <= '9':
			v = ord(s[0]) - ord('0')
		elif s[0] == 'T':
			v = 10
		elif s[0] == 'J':
			v = 11
		elif s[0] == 'Q':
			v = 12
		elif s[0] == 'K':
			v = 13
		else:
			v = 14

		self.val = v
		self.group = s[1] 
	def getVal(self, dic):
		suit = dic[self.group]
		return suit.getVal(self.val)
	def __str__(self):
		return "({0},{1})".format(self.val, self.group)
	def __repr__(self):
		return "({0},{1})".format(self.val, self.group)

dic = {
	's': None,
	'h': None,
	'd': None,
	'c': None
}

n = int(raw_input().strip())

cards = raw_input().strip().split()
cards = [ Card(x) for x in cards ]

#print "cards: ", cards


min_moves = 52 ** 2


visited = {
	's': False,
	'h': False,
	'd': False,
	'c': False
}

l = [ 0 ] * 4

def generateCase(l, n):
	global min_moves

	if n >= 4:
		for i in xrange(4):
			group, order = l[i]
			dic[group] = Suit(i, order)
		vals = [ card.getVal(dic) for card in cards ]

		lis = LIS(vals)

		#print "vals: ", vals, " lis: ", lis

		moves = len(vals) - lis
		min_moves = min(min_moves, moves)
	else:
		for group in ('s', 'h', 'd', 'c'):
			if not visited[group]:
				visited[group] = True
				for order in (True, False):
					l[n] = (group, order)
					generateCase(l, n+1)
				visited[group] = False

generateCase(l, 0)

print min_moves