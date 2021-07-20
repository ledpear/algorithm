import string
import sys
from collections import deque

input = sys.stdin.readline

nodeSize = int(input().rstrip())
nodeInfos = [[] for _ in range(nodeSize + 1)]

for _ in range(nodeSize - 1):
    nodeA, nodeB = map(int, input().split())

    nodeInfos[nodeA].append(nodeB)
    nodeInfos[nodeB].append(nodeA)

parentNodeArr = [0] * (nodeSize + 1)
visitNode = [False] * (nodeSize + 1)
queue = deque()
queue.append([1, 0]) #탐색할 노드, 부모 노드
visitNode[1] = True

while queue:
    nowNode, parentNode = queue.popleft()
    parentNodeArr[nowNode] = parentNode

    for nextNode in nodeInfos[nowNode]:
        if not visitNode[nextNode]:
            visitNode[nextNode] = True
            queue.append([nextNode, nowNode])

for i in range(2, nodeSize + 1):
    print(parentNodeArr[i])