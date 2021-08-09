import string
import sys
import heapq

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

nodeSize, edgeSize = map(int, input().split())
edges = [[] for _ in range(nodeSize + 1)]
for _ in range(edgeSize):
    nodeA, nodeB, cost = map(int, input().split())
    edges[nodeA].append([nodeB, cost])
    edges[nodeB].append([nodeA, cost])

visit = [False] * (nodeSize + 1)
hq = [[0, 1]] #cost, node
visitCount = 0
answer = 0

while visitCount != nodeSize:
    nowCost, nowNode = heapq.heappop(hq)
    if visit[nowNode]:
        continue

    visit[nowNode] = True
    visitCount += 1
    answer += nowCost

    for targetNode, targetCost in edges[nowNode]:
        if not visit[targetNode]:
            heapq.heappush(hq, [targetCost, targetNode])

print(answer)