import string
import sys

input = sys.stdin.readline

A = ' ' + input().rstrip()
B = ' ' + input().rstrip()

A_Size = len(A)
B_Size = len(B)

dp = [[""] * (B_Size) for _ in range(A_Size)]

for i in range(1, A_Size):
    for j in range(1, B_Size):
        if A[i] == B[j]:
            dp[i][j] = dp[i - 1][j - 1] + A[i]
        else:
            if len(dp[i][j - 1]) < len(dp[i - 1][j]):
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = dp[i][j - 1]

print(len(dp[-1][-1]))
print(dp[-1][-1])
