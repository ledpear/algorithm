import string
import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline
INF = int(1e9)

size = int(input().rstrip())
arr = list(map(int, input().split()))
dp = [INF] * size
dp[0] = 0

for idx in range(size):
    for jump in range(1, arr[idx] + 1):
        jumpIdx = idx + jump
        if jumpIdx < size:
            if dp[jumpIdx] > dp[idx] + 1:
                dp[jumpIdx] = dp[idx] + 1
        else:
            break

if dp[size - 1] == INF:
    print(-1)
else:
    print(dp[size - 1])