import copy
from collections import deque
import heapq

INF = 1e9

def dfs(visit, x, y, size_x, size_y, count):
    visit[x][y] = 1
    count[0] += 1

    move_x = [1, -1, 0, 0]
    move_y = [0, 0, 1, -1]

    for i in range(4):
        pos_x = x + move_x[i]
        pos_y = y + move_y[i]

        if pos_x >= 0 and pos_x < size_x and pos_y >= 0 and pos_y < size_y and visit[pos_x][pos_y] != 1:
            dfs(visit, pos_x, pos_y, size_x, size_y, count)

def bfs(visit, x, y, size_x, size_y):
    dq = deque()
    dq.append([x, y])
    visit[x][y] = 1
    count = 1

    move_x = [1, -1, 0, 0]
    move_y = [0, 0, 1, -1]

    while dq:
        now_x, now_y = dq.popleft()

        for i in range(4):
            pos_x = now_x + move_x[i]
            pos_y = now_y + move_y[i]

            if pos_x >= 0 and pos_x < size_x and pos_y >= 0 and pos_y < size_y and visit[pos_x][pos_y] != 1:
                dq.append([pos_x, pos_y]) 
                visit[pos_x][pos_y] = 1
                count += 1

    return count

#다익스트라
def dijkstra(start, size, edge_list):
    h = []
    heapq.heappush(h, (0, 1))

    cost_list = [INF] * (size + 1)
    
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

#일반적인 플로이드 위샬
def floyd_warshall(matrix, size):
    for i in range(size):
        for j in range(size):
            for k in range(size):
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])

#연결확인 플로이드 위샬
def floyd_warshall_custom(matrix, size):
    for k in range(size):
        for i in range(size):
            for j in range(size):
                if matrix[i][k] and matrix[k][j]:
                    matrix[i][j] = 1

#여러 값 입력받기
size_x, size_y, square_size = map(int, input().split())

#2차원 배열 생성
area = [[0] * size_y for x in range(size_x)]

#2차원 배열 입력
matrix = []
for i in range(10):
    matrix.append(list(map(int, input().split(' '))))

#새로운 객체를 생성하면서 복사
visit = copy.deepcopy(area)
