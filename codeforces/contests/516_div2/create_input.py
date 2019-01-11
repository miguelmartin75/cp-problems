import random
import sys
N = 2000
M = 2000

x = random.randint(1, N)
y = random.randint(1, M)
print("%d %d" % (N, M))
print("%d %d" % (x, y))

maxX = random.randint(1, 1000000000)
maxY = random.randint(1, 1000000000)
print("%d %d" % (maxX, maxY))

for i in range(N):
    for j in range(M):
        if (x == i - 1 and y == j - 1) or random.randint(0, 9) != 0:
            sys.stdout.write('.')
        else:
            sys.stdout.write('*')
    print()

