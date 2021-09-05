import string
import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

boardSize = int(input().rstrip())
boardArr = []
for _ in range(boardSize):
    boardArr.append(list(map(int, input().split())))

DpArr = [[0] * boardSize for _ in range(boardSize)]
DpArr[0][0] = 1

moveX = [1, 0]
moveY = [0, 1]

for x in range(boardSize):
    for y in range(boardSize):
        if boardArr[x][y] == 0:
            continue

        for dict in range(len(moveX)):
            posX = x + (moveX[dict] * boardArr[x][y])
            posY = y + (moveY[dict] * boardArr[x][y])

            if 0 <= posX < boardSize and 0 <= posY < boardSize:
                DpArr[posX][posY] += DpArr[x][y]

print(DpArr[-1][-1])