import string
import sys
from collections import deque
input = sys.stdin.readline

moveX = [1, -1, 0, 0]
moveY = [0, 0, 1, -1]

sizeX, sizeY = map(int, input().split())
matrix = []
for _ in range(sizeX):
    matrix.append(list(input().rstrip()))

maxScore = 1

queue = set()
queue.add((0,0, matrix[0][0]))

while queue:
    x, y, route = queue.pop()

    maxScore = max(maxScore, len(route))

    for dict in range(4):
        posX = x + moveX[dict]
        posY = y + moveY[dict]

        if posX < 0 or posX >= sizeX or posY < 0 or posY >= sizeY:
            continue
        elif matrix[posX][posY] not in route:
            queue.add((posX, posY, route + matrix[posX][posY]))

print(maxScore)