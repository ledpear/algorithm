import string
import sys
from collections import deque

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

testcase = int(input().rstrip())

for _ in range(testcase):
    nodeSize, edgeSize = map(int, input().split())

    edges = [[] for _ in range(nodeSize)]
    for _ in range(edgeSize):
        nodeA, nodeB = map(int, input().split())
        nodeA -= 1
        nodeB -= 1
        edges[nodeA].append(nodeB)
        edges[nodeB].append(nodeA)

    q = deque()
    visitNode = [False] * nodeSize
    group = 1
    bipatite = True
    for startNode in range(nodeSize):
        if not visitNode[startNode]: 
            q.append(startNode)
            visitNode[startNode] = group
            while q:
                nowNode = q.popleft()
                for nextNode in edges[nowNode]:
                    if not visitNode[nextNode]: 
                        q.append(nextNode)
                        visitNode[nextNode] = -1 * visitNode[nowNode]
                    elif visitNode[nowNode] == visitNode[nextNode]:
                        bipatite = False

    print('YES' if bipatite else 'NO')