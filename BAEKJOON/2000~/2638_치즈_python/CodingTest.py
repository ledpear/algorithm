import string
import sys

input = sys.stdin.readline

n, m = map(int, input().split())

matrix = []

count = 0
score = 0

for i in range(n):
    matrix.append(list(map(int, input().split())))
    for c in matrix[i]:
        if c:
            count += 1

def bfs():
    global matrix, n, m
    clear_pos = []

    move_x = [1, 0, -1, 0]
    move_y = [0, 1, 0, -1]

    score_pos = [[0] * m for _ in range(n)]
    visit = [[False] * m for _ in range(n)]
    queue = [[0,0]]
    visit[0][0] = True

    while queue:
        x, y = queue.pop(0)
            
        for i in range(4):
            pos_x = x + move_x[i]
            pos_y = y + move_y[i]

            if pos_x >= 0 and pos_x < n and pos_y >= 0 and pos_y < m and not visit[pos_x][pos_y]:
                if matrix[pos_x][pos_y]:
                    if score_pos[pos_x][pos_y] == 1:
                        visit[pos_x][pos_y] = True
                        clear_pos.append([pos_x,pos_y])
                    score_pos[pos_x][pos_y] += 1
                else:
                    visit[pos_x][pos_y] = True
                    queue.append([pos_x, pos_y])

    return clear_pos

def clearMatrix(clear_pos):
    global matrix, score, count

    for pos in clear_pos:
        x, y = pos
        matrix[x][y] = 0
        score += 1

    if score == count:
        return True
    else:
        return False

result = 0

if count == 0:
    print(result)
else:
    while True:
        clear_pos = bfs()
        if clearMatrix(clear_pos):
            print(result + 1)
            break
        else:
            result += 1