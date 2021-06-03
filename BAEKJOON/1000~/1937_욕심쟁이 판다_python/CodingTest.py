import string
import sys
import collections

input = sys.stdin.readline

#상하좌우로 이동
#옮긴 지역이 그 전 지역보다 대나무가 많아야함
#그런 지점이 없으면 종료

n = int(input().rstrip())
matrix = []

moveX = [1, -1, 0, 0]
moveY = [0, 0, 1, -1]

arr = []

for i in range(n):
    matrix.append(list(map(int, input().split())))
    for j in range(n):
        arr.append([matrix[i][j], i, j])

arr.sort(reverse=True)

DP = [[0] * n for _ in range(n)]
maxVal = 0

for node in arr:
    val, x, y = node
    DP[x][y] = 1

    for dir in range(4):
        posX = x + moveX[dir]
        posY = y + moveY[dir]
        
        if posX >= 0 and posX < n and posY >= 0 and posY < n:
            if DP[posX][posY] >= DP[x][y] and matrix[x][y] < matrix[posX][posY]:
                DP[x][y] = DP[posX][posY] + 1

    maxVal = max(maxVal, DP[x][y])

print(maxVal)