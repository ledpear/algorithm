import string
import sys
import heapq

input = sys.stdin.readline

n, k = map(int, input().split())
n_arr = [[] for _ in range(1000001)]
k_arr = []

for _ in range(n):
    w, v = map(int, input().split())
    heapq.heappush(n_arr[w], -v)

for _ in range(k):
    heapq.heappush(k_arr, int(input().rstrip()))

answer = 0

while k_arr:
    now_w = heapq.heappop(k_arr)

    maxVal = 0
    maxIndex = 0

    for i in range(1, now_w + 1):
        if not n_arr[i]:
            continue
        if maxVal < -n_arr[i][0]:
            maxVal = -n_arr[i][0]
            maxIndex = i
    
    if maxIndex != 0:
        answer += maxVal
        heapq.heappop(n_arr[maxIndex])

print(answer)