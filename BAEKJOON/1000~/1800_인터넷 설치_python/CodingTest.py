import string
import sys
import heapq

INF = 1e9
input = sys.stdin.readline

def dijkstra(start, limit):
    visit = [INF] * (node_size + 1)
    visit[start] = 0
    heap_list = []
    heapq.heappush(heap_list, [1,0])

    while heap_list:
        now_node, now_cost = heapq.heappop(heap_list)

        if now_cost > visit[now_node]:
            continue

        for edge in edges[now_node]:
            target_node, target_weight = edge
            
            if target_weight <= limit:
                if visit[target_node] > now_cost:
                    visit[target_node] = now_cost
                    heapq.heappush(heap_list, [target_node, now_cost])
            else:
                if visit[target_node] > now_cost + 1:
                    visit[target_node] = now_cost + 1
                    heapq.heappush(heap_list, [target_node, now_cost + 1])

    if visit[node_size] <= free_size:
        return True
    else:
        return False

node_size, edge_size, free_size = map(int, input().split())

edges = [[] for _ in range(node_size + 1)]
for i in range(edge_size):
    nodeA, nodeB, cost = map(int, input().split())
    edges[nodeA].append([nodeB, cost])
    edges[nodeB].append([nodeA, cost])

start = 0
end = 1000001
answer = INF

while start <= end:
    mid = (start + end) //2

    if dijkstra(1, mid):
        end = mid - 1
        answer = mid
    else:
        start = mid + 1

if answer == INF:
    print(-1)
else:
    print(answer)