import string
import sys

input = sys.stdin.readline

def KMP(mainStr, subStr):
    count = 0
    findPos = []

    piArr = getPiArr(subStr)

    mainSize = len(mainStr)
    subSize = len(subStr)

    mainIndex = 0
    subIndex = 0

    while mainIndex < mainSize:
        if mainStr[mainIndex] == subStr[subIndex]:
            mainIndex += 1
            subIndex += 1
        else:
            if subIndex != 0:
                subIndex = piArr[subIndex - 1]
            else:
                mainIndex += 1

        if subIndex == subSize:
            count += 1
            findPos.append(mainIndex - subSize + 1)
            subIndex = piArr[subIndex - 1]

    return count, findPos

def getPiArr(subStr):
    subSize = len(subStr)
    piArr = [0] * subSize

    sameCount = 0
    #0번째 인덱스는 비교할 문자가 없으므로 무조건 0 때문에 1부터 시작
    index = 1

    while index < subSize:
        if subStr[index] == subStr[sameCount]:
            sameCount += 1
            piArr[index] = sameCount
            index += 1
        else:
            if sameCount != 0:
                sameCount = piArr[sameCount - 1] 
            else:
                piArr[index] = 0
                index += 1

    return piArr

#입력
mainStr = input().rstrip()
subStr = input().rstrip()

#계산
count, findPos = KMP(mainStr, subStr)

#출력
print(count)
for pos in findPos:
    print(pos, end=' ')