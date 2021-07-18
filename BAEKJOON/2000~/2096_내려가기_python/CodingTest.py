import string
import sys
from copy import deepcopy

input = sys.stdin.readline

size = int(input().rstrip())
arr = []

arr = list(map(int, input().split()))

maxDP = deepcopy(arr)
minDP = deepcopy(arr)

for i in range(1, size):
    arr = list(map(int, input().split()))

    maxTemp = [0] * 3
    maxTemp[0] = arr[0] + max(maxDP[0], maxDP[1])
    maxTemp[1] = arr[1] + max(maxDP[0], maxDP[1], maxDP[2])
    maxTemp[2] = arr[2] + max(maxDP[2], maxDP[1])
    maxDP = maxTemp

    minTemp = [0] * 3
    minTemp[0] = arr[0] + min(minDP[0], minDP[1])
    minTemp[1] = arr[1] + min(minDP[0], minDP[1], minDP[2])
    minTemp[2] = arr[2] + min(minDP[2], minDP[1])
    minDP = minTemp

print(max(maxDP), end=' ')
print(min(minDP))