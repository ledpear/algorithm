import string
import sys
import heapq
import math

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

nodeSize = int(input().rstrip())
nodeInfo = []

for _ in range(nodeSize):
    x, y = map(float, input().split())
    nodeInfo.append([x, y])
    
hq = []
for i in range(nodeSize):
    for j in range(i + 1, nodeSize):
        distance = math.sqrt(pow(abs(nodeInfo[i][0] - nodeInfo[j][0]), 2) + pow(abs(nodeInfo[i][1] - nodeInfo[j][1]), 2))
        heapq.heappush(hq, [distance, i, j])

rootNodes = [i for i in range(nodeSize)]

def find(node):
    if rootNodes[node] == node:
        return node
    
    rootNodes[node] = find(rootNodes[node])
    return rootNodes[node]

count = 0
answer = 0
while count < nodeSize - 1:
    dist, nodeA, nodeB = heapq.heappop(hq)
    rootA = find(nodeA)
    rootB = find(nodeB)
    if rootA != rootB:
        answer += dist
        count += 1

        if nodeA < nodeB:
            rootNodes[rootB] = rootA
        else:
            rootNodes[rootA] = rootB

answer = round(answer, 2)
print(answer)