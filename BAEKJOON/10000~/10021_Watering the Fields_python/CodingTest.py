import string
import sys

INF = 10000000

input = sys.stdin.readline

n, c = map(int, input().split())
#k = input().rstrip()

positions = []
for _ in range(n):
    positions.append(list(map(int, input().split())))

arr = []

for i in range(n):
    for j in range(i+1, n):
        cost = int(pow(positions[i][0] - positions[j][0], 2) + pow(positions[i][1] - positions[j][1], 2))
        if cost >= c:
            arr.append([cost, i, j])

arr.sort()
node_table = [i for i in range(n)]

def getParent(node):
    global node_table
    if node == node_table[node]: return node
    node_table[node] = getParent(node)
    return node_table[node]

def checkParent(nodeA, nodeB):
    parentA = getParent(nodeA)
    parentB = getParent(nodeB)

    if parentA == parentB:
        return True
    else:
        return False

def unionParent(nodeA, nodeB):
    global node_table

    parentA = getParent(nodeA)
    parentB = getParent(nodeB)

    if parentA < parentB:
        node_table[parentB] = parentA
    else:
        node_table[parentA] = parentB

answer = 0

for edge in arr:
    cost, nodeA, nodeB = edge

    if not checkParent(nodeA, nodeB):
        answer += cost
        unionParent(nodeA, nodeB)

result = True
for i in range(0, n):
    if node_table[i] != 0:
        result = False
        break

if result:
    print(answer)
else:
    print(-1)