import heapq

INF = 1e9

def solution(N, road, K):
    answer = 0

    edge_list = [[] for _ in range(N + 1)]
    
    for r in road:
        edge_list[r[0]].append([r[1], r[2]])
        edge_list[r[1]].append([r[0], r[2]])
        
    h = []
    heapq.heappush(h, (0, 1))
    
    cost_list = [INF] * (N + 1)
    
    while h:
        cost, node = heapq.heappop(h)
        
        if cost_list[node] <= cost:
            continue
            
        cost_list[node] = cost
        
        for edge in edge_list[node]:
            end = edge[0]
            end_cost = edge[1] + cost
            
            if cost_list[end] > end_cost:
                heapq.heappush(h, (end_cost, end))
                
    for cost in cost_list:
        if cost <= K:
            answer += 1

    return answer