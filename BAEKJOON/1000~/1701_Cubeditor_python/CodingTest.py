import string
import sys

input = sys.stdin.readline

txt = input().rstrip()
txtSize = len(txt)

def getPiMax(txt):
    txtSize = len(txt)
    piArr = [0] * txtSize

    sameCount = 0
    index = 1
    maxCount = 0
    while index < txtSize:
        if txt[index] == txt[sameCount]:
            sameCount += 1
            piArr[index] = sameCount
            index += 1
        elif sameCount != 0:
            maxCount = max(maxCount, sameCount)
            sameCount = piArr[sameCount - 1]
        else:
            index += 1            

    maxCount = max(maxCount, sameCount)
    return maxCount

maxCount = 0
index = 0
while index < txtSize - maxCount:
    maxCount = max(maxCount, getPiMax(txt[index:]))
    index += 1

print(maxCount)