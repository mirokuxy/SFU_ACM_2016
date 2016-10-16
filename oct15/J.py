import sys

for line in sys.stdin:
	data = map(int, line.strip().split())
	
	height = data[0]
	bottom = data[1]
	top = data[2]
	
	bottom, top = max(bottom, top), min(bottom, top)

	sizes = data[3:]

	print height, bottom, top
	print sizes

	DP = [0] * (height + 1)
	for h in xrange(1, height + 1):
		for size in sizes:
			if size <= h:
				width = int( ( float(height - h) * float(bottom - top) /2 / float(height) ) * 2 + top )
				count = width / size
				volumn = (count ** 2) * (size ** 3)
				tot_volumn = DP[h - size] + volumn
				if tot_volumn > DP[h]:
					DP[h] = tot_volumn

	max_volumn = max(DP)

	print max_volumn

