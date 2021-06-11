import string
import sys

input = sys.stdin.readline

size = int(input().rstrip())

arr = list(map(int, input().split()))

#arr.sort()

minVal = 1
visit = set()


def BT(start, val):
    global minVal, visit, arr, size

    for i in range(start, size):
        val += arr[i]

        visit.add(val)
        if val == minVal:
            minVal += 1
            while minVal in visit:
                minVal += 1

        BT(i + 1, val)
        val -= arr[i]

BT(0, 0)


print(minVal)