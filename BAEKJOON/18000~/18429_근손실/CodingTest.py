import string
import sys

input = sys.stdin.readline

n, k = map(int, input().split())
arr = list(map(int, input().split()))

result = 0

def BT(score, used, count):
    global arr, result, n, k

    if count >= n:
        result += 1
        return

    score -= k

    for i in range(n):
        if not used[i]:
            if 500 <= score + arr[i]:
                used[i] = True
                BT(score + arr[i], used, count + 1)
                used[i] = False

BT(500, [False] * n, 0)

print(result)