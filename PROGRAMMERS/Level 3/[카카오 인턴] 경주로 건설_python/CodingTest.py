import string
import sys
from collections import deque

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

RIGHT = 0
DOWN = 1
LEFT = 2
UP = 3
INF = int(1e9)
moveX = [0, 1, 0, -1]
moveY = [1, 0, -1, 0]

def solution(board):
    answer = 0
    boardSize = len(board)
    boardCost = [[INF] * boardSize for _ in range(boardSize)]
    boardCost[0][0] = 0
    #비용, 방향, 위치
    queue = deque()
    queue.append([0, RIGHT, 0, 0])
    queue.append([0, DOWN, 0, 0])

    while queue:
        nowCost, nowDirection, nowX, nowY = queue.popleft()
        opposite = (nowDirection + 2) % 4
        for direction in range(4):
            if direction == opposite:
                continue

            posX = nowX + moveX[direction]
            posY = nowY + moveY[direction]

            if 0 <= posX < boardSize and 0 <= posY < boardSize and board[posX][posY] == 0:
                #방향에 따라 추가 비용이 달라진다
                additionalCost = 1
                if direction != nowDirection:
                    additionalCost += 5

                posCost = nowCost + additionalCost
                if boardCost[posX][posY] >= posCost:
                    boardCost[posX][posY] = posCost
                    queue.append([posCost, direction, posX, posY])


    return boardCost[boardSize - 1][boardSize - 1] * 100

board = [[0,0,0],[0,0,0],[0,0,0]]
print(solution(board))