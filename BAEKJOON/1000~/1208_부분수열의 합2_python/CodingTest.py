import string
import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

arrSize, target = map(int, input().split())
fullArr = list(map(int, input().split()))
leftArr = fullArr[:arrSize//2]
rightArr = fullArr[arrSize//2:]
count = 0

#크기와 합한 결과만 넘긴다
def BT(sumDict, numArr, count = 0, lastIndex = -1, sumResult = 0):
    if count != 0:
        if sumResult in sumDict:
            sumDict[sumResult] += 1
        else:
            sumDict[sumResult] = 1

    for index in range(lastIndex + 1, len(numArr)):
        sumResult += numArr[index]
        BT(sumDict, numArr, count + 1, index, sumResult)
        sumResult -= numArr[index]

#왼쪽과 오른쪽 배열의 조합의 합을 계산한다
leftSum = dict()
rightSum = dict()
BT(leftSum, leftArr)
BT(rightSum, rightArr)

#왼쪽이나 오른쪽에서 해당하는 값이 있는지 찾아서 결과에 반영
if target in leftSum:
    count += leftSum[target]

if target in rightSum:
    count += rightSum[target]

#왼쪽과 오른쪽을 더해서 목표값이 되는 경우를 이분탐색으로 찾아 결과에 반영
leftResult = sorted(leftSum.keys())
rightResult = sorted(rightSum.keys())

leftIndex = 0
rightIndex = len(rightResult) - 1

while leftIndex < len(leftResult) and rightIndex >= 0:
    sumVal = leftResult[leftIndex] + rightResult[rightIndex]
    if sumVal == target:
        count += leftSum[leftResult[leftIndex]] * rightSum[rightResult[rightIndex]]

    if sumVal < target:
        leftIndex += 1
    else:
        rightIndex -= 1
    
print(count)