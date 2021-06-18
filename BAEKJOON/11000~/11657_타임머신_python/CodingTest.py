import string
import sys

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

INF = int(1e9)

def bellman_ford(edges, start):
    distance = [INF] * (node_size + 1)

    distance[start] = 0

    for repeat in range(node_size):
        for node in range(1, node_size + 1):
            for target_node, cost in edges[node]:
                if distance[node] != INF and distance[target_node] > distance[node] + cost:
                    distance[target_node] = distance[node] + cost
                    if repeat == node_size - 1:
                        return False, distance
    
    return True, distance


node_size, edge_size = map(int, input().split())

edges = [[] for _ in range(node_size + 1)]
for _ in range(edge_size):
    start, end, cost = map(int, input().split())
    edges[start].append((end, cost))

result, distance = bellman_ford(edges, 1)

if not result:
    print("-1")
else:
    for i in range(2, node_size + 1):
        if distance[i] != INF:
            print(distance[i])
        else:
            print(-1)