import string
import sys

input = sys.stdin.readline

A = ' ' + input().rstrip()
B = ' ' + input().rstrip()
C = ' ' + input().rstrip()

A_Size = len(A)
B_Size = len(B)
C_Size = len(C)

dp = [[[0]*C_Size for _ in range(B_Size)] for _ in range(A_Size)]

for i in range(1, A_Size):
    for j in range(1, B_Size):
        for z in range(1, C_Size):
            if A[i] == B[j] == C[z]:
                dp[i][j][z] = dp[i - 1][j - 1][z - 1] + 1
            else:
                dp[i][j][z] = max(dp[i - 1][j][z], dp[i ][j - 1][z], dp[i][j][z - 1], dp[i - 1][j - 1][z], dp[i - 1][j][z - 1], dp[i][j - 1][z - 1])

print(dp[-1][-1][-1])