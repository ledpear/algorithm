import string
import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

inputArr = []

while True:
    try:
        inputArr.append(int(input().rstrip()))
    except:
        break

def postorderPrint(start, end):
    if start >= end:
        return

    div = end
    for index in range(start + 1, end):
        if inputArr[start] < inputArr[index]:
            div = index
            break

    postorderPrint(start + 1, div)
    postorderPrint(div, end)
    print(inputArr[start])

postorderPrint(0, len(inputArr))