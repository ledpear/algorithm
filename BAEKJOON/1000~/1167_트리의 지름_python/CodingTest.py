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

for _ in range(node_size):
    input_list = list(map(int, input().split()))

    node = input_list[0]

    index = 1
    while input_list[index] != -1:
        nodes[node].append((input_list[index], input_list[index + 1])) #노드, 거리
        index += 2

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