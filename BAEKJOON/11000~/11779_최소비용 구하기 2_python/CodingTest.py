import string
import sys
import heapq
import copy

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

INF = int(1e9)

node_size = int(input().rstrip())
edge_size = int(input().rstrip())

edges = [[] for _ in range(node_size + 1)]

for _ in range(edge_size):
    start, end, cost = map(int, input().split())
    edges[start].append([end, cost])

start_node, end_node = map(int, input().split())

def dijkstra():
    dist = [INF for _ in range(node_size + 1)]
    routes = [[] for _ in range(node_size + 1)]
    queue = [[start_node, 0]]

    while queue:
        now_node, now_cost = heapq.heappop(queue)

        if dist[now_node] < now_cost:
            continue

        routes[now_node].append(now_node)

        if now_node == end_node:
            dist[end_node], routes[end_node]
        
        for target_node, target_cost in edges[now_node]:
            target_cost += now_cost
            if dist[target_node] > target_cost:
                dist[target_node] = target_cost
                routes[target_node] = copy.deepcopy(routes[now_node])
                heapq.heappush(queue, [target_node, target_cost])

    return dist[end_node], routes[end_node]

answer, route = dijkstra()
print(answer)
print(len(route))
for node in route:
    print(node, end=' ')
