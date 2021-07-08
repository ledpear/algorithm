import string
import sys
import math

input = sys.stdin.readline

num = int(input().rstrip())

dp = [0,1]

for i in range(2, num+1):
    min_val = 4
    j = 1

    while (j**2) <= i:
        min_val = min(min_val, dp[i - (j**2)])
        j += 1

    dp.append(min_val + 1)

print(dp[num])