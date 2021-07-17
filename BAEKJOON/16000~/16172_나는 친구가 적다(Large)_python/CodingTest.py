import string
import sys

input = sys.stdin.readline

mainStr = input().rstrip()
subStr = input().rstrip()

#KMP알고리즘을 구현하고
#문자열을 숫자는 건너 뛰면서 탐색한다

def getPiArr(subStr):
    subSize = len(subStr)
    piArr = [0] * subSize

    index = 1
    sameCount = 0

    while index < subSize:
        if subStr[index] == subStr[sameCount]:
            sameCount += 1
            piArr[index] = sameCount
            index += 1
        elif sameCount != 0:
            sameCount = piArr[sameCount - 1]
        else:
            index += 1
    
    return piArr

def KMP(mainStr, subStr):
    mainSize = len(mainStr)
    subSize = len(subStr)

    piArr = getPiArr(subStr)

    subIndex = 0
    mainIndex = 0

    while mainIndex < mainSize:
        if mainStr[mainIndex] in string.digits:
            mainIndex += 1
            continue
        elif mainStr[mainIndex] == subStr[subIndex]:
            mainIndex += 1
            subIndex += 1

            if subIndex == subSize:
                return True

        elif subIndex != 0:
            subIndex = piArr[subIndex - 1]
        else:
            mainIndex += 1

    return False

if KMP(mainStr, subStr):
    print(1)
else:
    print(0)