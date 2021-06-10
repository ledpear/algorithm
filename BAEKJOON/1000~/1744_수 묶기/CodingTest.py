import string
import sys
import heapq

input = sys.stdin.readline

size = int(input().rstrip())
plus_num = []
minus_num = []
answer = 0

for _ in range(size):
    temp = int(input().rstrip())
    if temp == 1:
        answer += 1
    elif temp > 0:
        heapq.heappush(plus_num, -temp)
    else:
        heapq.heappush(minus_num, temp)


temp = 0
while plus_num:
    if temp == 0:
        temp = -heapq.heappop(plus_num)
    else:
        answer += temp * -heapq.heappop(plus_num)
        temp = 0

if temp != 0:
    answer += temp

temp = 0
while minus_num:
    if temp == 0:
        temp = heapq.heappop(minus_num)
    else:
        answer += temp * heapq.heappop(minus_num)
        temp = 0

if temp != 0:
    answer += temp

print(answer)