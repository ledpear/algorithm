import copy
from collections import deque

def setSquare(area, point1_x, point1_y, point2_x, point2_y):
    for x in range(point1_x, point2_x):
        for y in range(point1_y, point2_y):
            area[x][y] = 1

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


size_x, size_y, square_size = map(int, input().split())
area = [[0] * size_y for x in range(size_x)]

for square_index in range(square_size):
    point1_y, point1_x, point2_y, point2_x = map(int, input().split())

    setSquare(area, point1_x, point1_y, point2_x, point2_y)

visit = copy.deepcopy(area)
answer = []

for x in range(size_x):
    for y in range(size_y):
        if visit[x][y] == 0:
            answer.append(bfs(visit, x, y, size_x, size_y))

print(len(answer))
for result in sorted(answer):
    print(result, end=' ')