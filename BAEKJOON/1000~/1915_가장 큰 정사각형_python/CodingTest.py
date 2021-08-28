import string
import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

sizeX, sizeY = map(int, input().split())
board = []
for _ in range(sizeX):
    temp = list(input().rstrip())
    for i in range(sizeY):
        temp[i] = ord(temp[i]) - ord('0')
    board.append(temp)

answer = 0
dp = [[0] * (sizeY + 1) for _ in range(sizeX + 1)]
for x in range(1, sizeX + 1):
    for y in range(1, sizeY + 1):
        if board[x - 1][y - 1] == 1:
            dp[x][y] = min(dp[x - 1][y - 1], dp[x][y - 1], dp[x - 1][y]) + 1
            answer = max(answer, dp[x][y])
                

print(int(pow(answer, 2)))