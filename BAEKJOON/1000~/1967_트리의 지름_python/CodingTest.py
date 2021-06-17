import string
import sys

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

maxVal = [0]
target_node = [0]
node_size = int(input().rstrip())
nodes = [[] for _ in range(node_size + 1)]
terminal_nodes = []

for _ in range(node_size - 1):
    nodeA, nodeB, cost = list(map(int, input().split()))

    nodes[nodeA].append((nodeB, cost)) #노드, 거리
    nodes[nodeB].append((nodeA, cost)) #노드, 거리

def bfs(start):
    visit = [False] * (node_size + 1)

    queue = [[start, 0]] #노드, 거리
    visit[start] = True

    while queue:
        now_node, now_cost = queue.pop(0)

        if maxVal[0] < now_cost:
                target_node[0] = now_node
                maxVal[0] = now_cost

        for next_node, next_cost in nodes[now_node]:
            if not visit[next_node]:
                visit[next_node] = True
                queue.append((next_node, now_cost + next_cost))

bfs(1)
bfs(target_node[0])

print(maxVal[0])