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

for i in range(x):
    for j in range(y):
        if matrix[i][j] == 'L':
            bfs(i, j, x, y)

print(maxVal)