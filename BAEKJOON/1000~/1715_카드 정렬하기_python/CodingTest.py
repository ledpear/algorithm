import string
import sys
import heapq

input = sys.stdin.readline

size = int(input().rstrip())
hq = []

for _ in range(size):
    heapq.heappush(hq, int(input().rstrip()))

score = 0
count = 0
arr = [0, 0]
while hq:
    arr[count] = heapq.heappop(hq)
    count += 1
    if count == 2:
        count = 0
        sumVal = arr[0] + arr[1]
        heapq.heappush(hq, sumVal)
        score += sumVal

print(score)
