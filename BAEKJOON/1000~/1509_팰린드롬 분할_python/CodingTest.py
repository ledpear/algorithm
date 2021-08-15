import string
import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

inputText = input().rstrip()
answer = int(1e9)
def BT(text, arr, startIndex = 0):
    global answer

    if startIndex == len(text):
        answer = min(answer, len(arr))
        return

    #시작 위치부터 끝까지 탐색
    for index in range(startIndex, len(text)):
        #만약 시작과 끝이 같다면 팰린드롬인지 확인
        if text[startIndex] == text[index]:
            leftIndex = startIndex
            rightIndex = index
            isPalindrome = True

            #다른 곳이 없으면
            while leftIndex < rightIndex:
                if text[leftIndex] != text[rightIndex]:
                    isPalindrome = False
                    break
                leftIndex += 1
                rightIndex -= 1
            
            #패턴 추가
            if isPalindrome:
                arr.append(text[startIndex:index + 1])
                BT(text, arr, index + 1)
                arr.pop()

BT(inputText, [])
print(answer)