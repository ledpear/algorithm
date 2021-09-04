import string
import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

INF = int(1e9)
money = int(input().rstrip())

if money <= 5:
    dp = [-1, -1, 1, -1, 2, 1]
else:
    dp = [INF] * (money + 1)
    dp[2] = 1
    dp[4] = 2
    dp[5] = 1
    for idx in range(6, money + 1):
        dp[idx] = min(dp[idx - 2], dp[idx - 5])
        if dp[idx] != INF:
            dp[idx] += 1

print(dp[money])