import string
import sys
import heapq

input = sys.stdin.readline

INF = 1e9

N, Q = map(int, input().split())
#k = input().rstrip()

#0은 플래그 나머지는 거리
matrix = [[INF] * (N + 1) for _ in range(N + 1)]
default = [[False] * (N + 1) for _ in range(N + 1)]

#for i in range(1, N + 1):
#    matrix[i][i] = 0

for _ in range(N - 1):
    nodeA, nodeB, usado = map(int, input().split())
    matrix[nodeA][nodeB] = usado
    matrix[nodeB][nodeA] = usado
    default[nodeA][nodeB] = True
    default[nodeB][nodeA] = True

def Dijkstra(target):
    global matrix
    global default

    size = len(matrix)
    heap = []
    heapq.heappush(heap, [0, target])
    visit = [INF] * size

    while heap:
        heap_pop = heapq.heappop(heap)
        now_cost = heap_pop[0]
        now_node = heap_pop[1]

        if visit[now_node] > now_cost:
            matrix[target][now_node] = now_cost
            matrix[now_node][target] = now_cost
            visit[now_node] = now_cost

            for i in range(1, size):
                if i == now_node : continue
                if matrix[target][now_node] == INF or matrix[now_node][i] == INF: continue
                if matrix[target][now_node] == 0 or matrix[now_node][i] == 0: continue

                new_cost = min(matrix[target][now_node], matrix[now_node][i])
                    

                if visit[i] > new_cost:
                     heapq.heappush(heap, [new_cost, i])

size = len(matrix)


for _ in range(Q):
    usado, target = map(int, input().split())

    result = 0

    if matrix[target][0] == INF:
        #Dijkstra(target)
        matrix[target][0] = 0

        for j in range(1, size):
            if target == j : continue

            for k in range(1, size):
                if target == k: continue
                if matrix[target][k] == INF or matrix[k][j] == INF: continue
                matrix[target][j] = min(matrix[target][j] , matrix[target][k], matrix[k][j])


    for i in range(1, size):
        if matrix[target][i] != INF and matrix[target][i] >= usado:
            result += 1
    print(result)