import sys
from collections import deque

class UnionSet(object):
    def __init__(self, n):
        self.groups = [ i for i in xrange(n+1) ]
        self.count = n      # exclude 0
        self.maxGroup = n
    def findGroup(self, i):
        q = []
        while self.groups[i] != i:
            q.append(i)
            i = self.groups[i]
        for j in q:
            self.groups[j] = i
        return i
    def joinGroup(self, i, j):
        gi = self.findGroup(i)
        gj = self.findGroup(j)
        if gi != gj:
            self.groups[gi] = gj
            self.count -= 1
    def countGroup(self):
        return self.count
    def newGroup(self):
        self.maxGroup += 1
        self.groups.append(self.maxGroup)
        self.count += 1
        return self.maxGroup


n,m,q = map(int, raw_input().strip().split())

queries = []

for i in xrange(q):
    x1,y1, x2,y2 = map(int, raw_input().strip().split())
    queries.append((x1 -1,y1 -1,x2 -1,y2 -1))

matrix = [ [0]*m for i in xrange(n) ]
group = [ [-1]*m for i in xrange(n) ]

for (x1,y1,x2,y2) in queries:
    squares = [ (x,y) for x in xrange(x1,x2+1) for y in xrange(y1, y2+1) ]
    for (x,y) in squares:
        matrix[x][y] += 1

def markGroup(x,y, i):
    q = deque([])
    q.append((x,y))

    while len(q) >0:
        x,y = q.popleft()
        group[x][y] = i

        for (dx,dy) in [ (1,0), (-1,0), (0,1), (0,-1) ]:
            xx, yy = x + dx, y + dy
            if 0 <= xx < n and 0 <= yy < m and matrix[xx][yy] == 0 and group[xx][yy] == -1:
                q.append((xx,yy))


groupCount = 0
for i in xrange(n):
    for j in xrange(m):
        if matrix[i][j] == 0 and group[i][j] == -1:
            groupCount += 1
            markGroup(i,j, groupCount)

uSet = UnionSet(groupCount)
count = []

for i in xrange(len(queries)-1, -1, -1):
    count.append(uSet.countGroup())

    x1,y1,x2,y2 = queries[i]
    squares = [ (x,y) for x in xrange(x1,x2+1) for y in xrange(y1, y2+1) ]
    for (x,y) in squares:
        matrix[x][y] -= 1
        if matrix[x][y] == 0:
            group[x][y] = uSet.newGroup()
            for (dx,dy) in [ (1,0), (-1,0), (0,1), (0,-1) ]:
                xx, yy = x + dx, y + dy
                if 0 <= xx < n and 0 <= yy < m and matrix[xx][yy] == 0:
                    uSet.joinGroup(group[x][y], group[xx][yy])

count.reverse()

for g in count:
    print g






























