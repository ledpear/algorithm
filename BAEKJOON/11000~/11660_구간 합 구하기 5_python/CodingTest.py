import string
import sys

input = sys.stdin.readline

matrixSize, testSize = map(int, input().split())

matrix = []
for _ in range(matrixSize):
    matrix.append(list(map(int, input().split())))

for x in range(matrixSize):
    for y in range(matrixSize):
        if x > 0:
            matrix[x][y] += matrix[x - 1][y]
        if y > 0:
            matrix[x][y] += matrix[x][y - 1]
        if x > 0 and y > 0:
            matrix[x][y] -= matrix[x - 1][y - 1]

for _ in range(testSize):
    startX, startY, endX, endY = map(int, input().split())
    startX -= 1
    startY -= 1
    endX -= 1
    endY -= 1

    answer = 0
    answer += matrix[endX][endY]

    if startX > 0:
        answer -= matrix[startX - 1][endY]
    if startY > 0:
        answer -= matrix[endX][startY - 1]
    if startX > 0 and startY > 0:
        answer += matrix[startX - 1][startY - 1]
    
    print(answer)