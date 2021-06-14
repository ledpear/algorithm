import string
import sys
import heapq

input = sys.stdin.readline

n, k = map(int, input().split())
n_arr = []
k_arr = []

for _ in range(n):
    heapq.heappush(n_arr, list(map(int, input().split())))

for _ in range(k):
    heapq.heappush(k_arr, int(input().rstrip()))

answer = 0
cal = []

while k_arr:
    now_w = heapq.heappop(k_arr)

    while n_arr and n_arr[0][0] <= now_w:
        now_m, now_v = heapq.heappop(n_arr)
        heapq.heappush(cal, -now_v)

    if cal:
        answer -= heapq.heappop(cal)
    elif not n_arr:
        break

print(answer)