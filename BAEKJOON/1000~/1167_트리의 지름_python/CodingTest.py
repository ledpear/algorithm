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

    if index == 3: #인덱스가 3이면 하나만 추가된것
        terminal_nodes.append(node)

#시작과 끝 노드를 저장해서 이미 방문됐으면 리스트에서 제외
#끝노드를 방문할 때마다 추가
visitTerminalNode = [[] for _ in range(node_size + 1)]

def bfs(start):
    visit = [False] * (node_size + 1)

    #이미 도달한 말단노드는 제외
    for n in visitTerminalNode[start]:
        visit[n] = True

    queue = [[start, 0]] #노드, 거리
    visit[start] = True

    while queue:
        now_node, now_cost = queue.pop(0)

        if now_node in terminal_nodes and start != now_node:
            if maxVal[0] < now_cost:
                target_node[0] = now_node
                maxVal[0] = now_cost

            visitTerminalNode[start].append(now_node)
            visitTerminalNode[now_node].append(start)
            continue

        for next_node_info in nodes[now_node]:
            next_node, next_cost = next_node_info

            if not visit[next_node]:
                visit[next_node] = True
                queue.append((next_node, now_cost + next_cost))

bfs(1)
bfs(target_node[0])

print(maxVal[0])