import string
import sys
import heapq

INF = 1e9
input = sys.stdin.readline

node_size, edge_size, free_size = map(int, input().split())

edges = [[] for _ in range(node_size + 1)]
for i in range(edge_size):
    nodeA, nodeB, cost = map(int, input().split())
    edges[nodeA].append([nodeB, cost])
    edges[nodeB].append([nodeA, cost])

cost_arr = [INF] * (node_size + 1)
heap_list = []
heapq.heappush(heap_list, [1,0])


while heap_list:
    now_node, now_cost = heapq.heappop(heap_list)

    if cost_arr[now_node] <= now_cost:
        continue

    cost_arr[now_node] = now_cost

    for edge in edges[now_node]:
        target_node, target_cost = edge
        
        heapq.heappush(heap_list, [target_node, target_cost + now_cost])

print(cost_arr[node_size])
