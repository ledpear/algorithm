import copy
from collections import deque

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

visit = copy.deepcopy(area)

print("test", end=' ')    