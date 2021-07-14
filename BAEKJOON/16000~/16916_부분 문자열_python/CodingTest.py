import string
import sys

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

input_mainstr = input().rstrip()
input_substr = input().rstrip()

def KMPSearch(input_substr, input_mainstr):
    result = 0
    subSize = len(input_substr)
    mainSize = len(input_mainstr)

    lps = [0]*subSize

    # Preprocess the input_substrtern
    computeLPS(input_substr, lps)

    mainIndex = 0  # index for input_mainstr[]
    subIndex = 0  # index for input_substr[]
    while mainIndex < mainSize:
        # 문자열이 같은 경우 양쪽 인덱스를 모두 증가시킴
        if input_substr[subIndex] == input_mainstr[mainIndex]:
            mainIndex += 1
            subIndex += 1
        # input_substrtern을 찾지 못한 경우
        elif input_substr[subIndex] != input_mainstr[mainIndex]:
            # j!=0인 경우는 짧은 lps에 대해 재검사
            if subIndex != 0:
                subIndex = lps[subIndex-1]
            # j==0이면 일치하는 부분이 없으므로 인덱스 증가
            else:
                mainIndex += 1

        # input_substrtern을 찾은 경우
        if subIndex == subSize:
            result += 1
            #return result
            # 이전 인덱스의 lps값을 참조하여 계속 검색
            subIndex = lps[subIndex-1]

    return result

def computeLPS(input_substr, lps):
    leng = 0  # length of the previous longest prefix suffix

    # 항상 lps[0]==0이므로 while문은 i==1부터 시작한다.
    i = 1
    while i < len(input_substr):
        # 이전 인덱스에서 같았다면 다음 인덱스만 비교하면 된다.
        if input_substr[i] == input_substr[leng]:
            leng += 1
            lps[i] = leng
            i += 1
        else:
            # 일치하지 않는 경우
            if leng != 0:
                # 이전 인덱스에서는 같았으므로 leng을 줄여서 다시 검사
                leng = lps[leng-1]
                # 다시 검사해야 하므로 i는 증가하지 않음
            else:
                # 이전 인덱스에서도 같지 않았다면 lps[i]는 0 이고 i는 1 증가
                lps[i] = 0
                i += 1

print(KMPSearch(input_substr, input_mainstr))
