import sys


def getDigits(n):
	digits = set([])
	while n > 0:
		digit = n % 10
		digits.add(digit)

		n = n /10

	return digits

for line in sys.stdin:
	n = int(line.strip())

	digits = [False] * (10)
	k = 0
	while True:
		k += 1
		m = n * k
		used = getDigits(m)
		for x in used:
			digits[x] = True

		if all(digits):
			break

	print k



