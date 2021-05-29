import string
import sys
import heapq

INF = 10000000

input = sys.stdin.readline

n, c = map(int, input().split())
#k = input().rstrip()

positions = []
for _ in range(n):
    positions.append(list(map(int, input().split())))

heap = []
heapq.heappush(heap, [0,0])
visit = [False] * n
answer = 0

while heap:
    cost, node = heapq.heappop(heap)
    if visit[node]: continue
    visit[node] = True
    answer += cost

    for i in range(n):
        if not visit[i]:
            new_cost = int(pow(positions[node][0] - positions[i][0], 2) + pow(positions[node][1] - positions[i][1], 2))
            if new_cost >= c:
                heapq.heappush(heap, [new_cost, i])

result = True
for i in range(n):
    if not visit[i]:
        result = False
        break

if result:
    print(answer)
else:
    print(-1)