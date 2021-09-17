import string
import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

size = int(input().rstrip())

history = set()
inputList = []

answer = 0

for _ in range(size * 2):
    inputStr = input().rstrip()
    if inputStr in history:
        delIdx = 0
        if inputStr != inputList[0]:
            answer += 1
            delIdx = inputList.index(inputStr)
        
        del(inputList[delIdx])
                
        history.remove(inputStr)
    else:
        history.add(inputStr)
        inputList.append(inputStr)

print(answer)