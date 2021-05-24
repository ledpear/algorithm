import string
import sys
import heapq
from copy import deepcopy
from typing import Deque

input = sys.stdin.readline

INF = 1e9

N, Q = map(int, input().split())

edges = [[] for _ in range(N + 1)]

for _ in range(N - 1):
    nodeA, nodeB, usado = map(int, input().split())
    edges[nodeA].append([nodeB, usado])
    edges[nodeB].append([nodeA, usado])

def bfs(target, k):
    global N
    global edges
    visit = [False] * (N + 1)
    q = Deque()
    q.append([target, INF])
    result = 0
    
    while q:
        now_node, now_cost = q.popleft()

        if now_cost >= k and not visit[now_node]:
            result += 1
            visit[now_node] = True
            q.extend(edges[now_node])
    
    return result - 1

for _ in range(Q):
    usado, target = map(int, input().split())

    
    print(bfs(target, usado))