import string
import heapq

def solution(files):
    answer = []

    headDict = {}
    for fileIdx, fileName in enumerate(files):
        idx = 0
        head = ''
        number = ''
        tail = ''

        while fileName[idx] not in string.digits:
            head += fileName[idx]
            idx += 1

        while fileName[idx] in string.digits:
            number += fileName[idx]
            idx += 1
            if idx == len(fileName):
                break

        tail = fileName[idx:]
        head = head.lower()
        number = int(number)

        if head in headDict:
            if number in headDict[head]:
                headDict[head][number].append(fileIdx)
            else:
                headDict[head][number] = [fileIdx]
        else:
            headDict[head] = {int(number): [fileIdx]}

    for head in sorted(headDict.keys()):
        for number in sorted(headDict[head].keys()):
            for fileIdx in headDict[head][number]:
                answer.append(files[fileIdx])


    return answer

print(solution(["i0", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"]))
print(solution(["F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"]))