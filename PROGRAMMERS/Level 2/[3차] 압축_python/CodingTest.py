def getIdx(cha):
    return ord(cha) - 64

def solution(msg):
    answer = []
    dictionary = [[] for _ in range(27)]

    idx = 0

    while idx < len(msg):
        #한글자식 비교하면서 등록되어 있는지 확인한다
        nowIdx = getIdx(msg[idx])
        nowDict = dictionary[nowIdx]
        
        while idx < len(msg):
            next = False
            idx += 1
            
            #마지막 글자라면 어차피 다음에 탐색할게 없으니 종료한다
            if idx >= len(msg):
                break

            for nextChar, nextIdx in nowDict:
                if nextChar == msg[idx]:
                    next = True
                    nowDict = dictionary[nextIdx]
                    nowIdx = nextIdx
                    break
            
            if not next:
                #다음 문자가 없으면 해당 문자를 추가해준다
                nowDict.append([msg[idx], len(dictionary)])
                dictionary.append([])
                break
        
        answer.append(nowIdx)

    return answer

print(solution("KAKAO"))
print(solution("TOBEORNOTTOBEORTOBEORNOT"))
print(solution("ABABABABABABABAB"))