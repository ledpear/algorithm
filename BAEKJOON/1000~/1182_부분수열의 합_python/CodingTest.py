import string
import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

arrSize, target = map(int, input().split())
numArr = list(map(int, input().split()))
count = 0

def BT(nowArr, lastIndex):
    global count

    if len(nowArr) != 0 and sum(nowArr) == target:
        count += 1

    for index in range(lastIndex + 1, arrSize):
        nowArr.append(numArr[index])
        BT(nowArr, index)
        nowArr.pop()

BT([], -1)

print(count)