import string
import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

size = int(input().rstrip())

numArr = list(map(int, input().split()))

nowArr = []
used = [False] * size
maxVal = 0

def backTracking():
    global maxVal

    if len(nowArr) == size:
        sumVal = 0
        for idx in range(size - 1):
            sumVal += abs(nowArr[idx] - nowArr[idx + 1])
        maxVal = max(maxVal, sumVal)
        return

    for idx in range(size):
        if not used[idx]:
            used[idx] = True
            nowArr.append(numArr[idx])
            backTracking()
            used[idx] = False
            nowArr.pop()

backTracking()
print(maxVal)      