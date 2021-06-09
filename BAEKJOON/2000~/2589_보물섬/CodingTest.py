import string
import sys

input = sys.stdin.readline

x, y = map(int, input().split())
matrix = []

for _ in range(x):
    matrix.append(input().rstrip())

maxVal = 0

moveX = [1, -1, 0, 0]
moveY = [0, 0, 1, -1]

visit = [[False] * y for _ in range(x)]
finds = []

for i in range(x):
    if not visit[i][0] and matrix[i][0] == 'L':
        visit[i][0] = True
        finds.append([i, 0])
    if not visit[i][-1] and matrix[i][-1] == 'L':
        visit[i][-1] = True
        finds.append([i, y-1])

for j in range(y):
    if not visit[0][j] and matrix[0][j] == 'L':
        visit[0][j] = True
        finds.append([0, j])
    if not visit[-1][j] and matrix[-1][j] == 'L':
        visit[-1][j] = True
        finds.append([x-1, j])

for i in range(x):
    for j in range(y):
        if not visit[i][j] and matrix[i][j] == 'W':
            queue = [[i, j]]
            visit[i][j] = True

            while queue:
                nowX, nowY = queue.pop(0)
                
                for dir in range(4):
                    posX = nowX + moveX[dir]
                    posY = nowY + moveY[dir]

                    if posX >= 0 and posY >= 0 and posX < x and posY < y:
                        if not visit[posX][posY]:
                            visit[posX][posY] = True
                            if matrix[posX][posY] == 'W':
                                queue.append([posX, posY])
                            else:
                                finds.append([posX, posY])


def bfs(x, y, sizeX, sizeY):
    global matrix, moveX, moveY, maxVal

    visit = [[False] * sizeY for _ in range(sizeX)]

    queue = [[x, y, 0]]
    visit[x][y] = True

    while queue:
        nowX, nowY, nowScore = queue.pop(0)
        maxVal = max(nowScore, maxVal)
        
        for i in range(4):
            posX = nowX + moveX[i]
            posY = nowY + moveY[i]

            if posX >= 0 and posY >= 0 and posX < sizeX and posY < sizeY:
                if not visit[posX][posY] and matrix[posX][posY] == 'L':
                    visit[posX][posY] = True
                    queue.append([posX, posY, nowScore + 1])

for find in finds:
    i, j = find
    bfs(i, j, x, y)

print(maxVal)