import string
import sys

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

INF = 1e9
testcase = int(input().rstrip())

def bellman_ford(edges, start):
    distance = [INF] * (node_size + 1)
    pre_visit = [0] * (node_size + 1)

    distance[start] = 0

    for _ in range(node_size - 1):
        for node in range(1, node_size + 1):
            for target_node, cost in edges[node]:
                if distance[target_node] > distance[node] + cost:
                    distance[target_node] = distance[node] + cost
                    pre_visit[target_node] = node

    for node in range(1, node_size + 1):
        for target_node, cost in edges[node]:
            if distance[target_node] > distance[node] + cost:
                return True
    
    return False

for _ in range(testcase):
    node_size, edge_size, wormhole_size = map(int, input().split())
    total_edge_size = edge_size + wormhole_size

    edges = [[] for _ in range(node_size + 1)]
    for _ in range(edge_size):
        node_A, node_B, cost = map(int, input().split())
        edges[node_A].append((node_B, cost))
        edges[node_B].append((node_A, cost))

    for _ in range(wormhole_size):
        start, end, cost = map(int, input().split())
        edges[start].append((end, -cost))

    if bellman_ford(edges, 1):
        print('YES')
    else:
        print("NO")



