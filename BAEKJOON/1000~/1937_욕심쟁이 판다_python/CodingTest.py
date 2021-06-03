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

for _ in range(n):
    matrix.append(list(map(int, input().split())))

DP = [[0] * n for _ in range(n)]
maxVal = 0

for i in range(n):
    for j in range(n):

        if DP[i][j] < 1:
            dq = collections.deque()
            dq.append([i,j, 1])
            visit = [[False] * n for _ in range(n)]

            while dq:
                x , y, val = dq.popleft()
                if DP[x][y] >= val or visit[x][y]:
                    continue

                DP[x][y] = val
                maxVal = max(maxVal, val)
                visit[x][y] = True
                
                val += 1
                for dir in range(4):
                    posX = x + moveX[dir]
                    posY = y + moveY[dir]
                    
                    if posX >= 0 and posX < n and posY >= 0 and posY < n:
                        if DP[posX][posY] < val and matrix[x][y] < matrix[posX][posY]:
                            dq.append([posX, posY, val])


print(DP)