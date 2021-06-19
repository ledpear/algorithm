import string
import sys
from collections import deque

input = sys.stdin.readline
INF = 1e9

#n, m = map(int, input().split())
#k = input().rstrip()

start, target = map(int, input().split())

def BFS_0_1(start, target):
    visit = [False] * 200001
    dist = [INF] * 200001
    queue = []
    queue.append([start, 0])
    visit[start] = True
    dist[start] = 0

    while queue:
        now, cost = queue.pop(0)

        if now * 2 <= 200000 and not visit[now * 2]:
            visit[now * 2] = True
            dist[now * 2] = cost
            queue.insert(0, [now * 2, cost])

        if now - 1 >= 0 and not visit[now - 1]:
            visit[now - 1] = True
            dist[now - 1] = cost + 1
            queue.append([now - 1, cost + 1])
            

        if now + 1 <= 200000 and not visit[now + 1]:
            visit[now + 1] = True
            dist[now + 1] = cost + 1
            queue.append([now + 1, cost + 1])
            
    return dist[target]

print(BFS_0_1(start, target))