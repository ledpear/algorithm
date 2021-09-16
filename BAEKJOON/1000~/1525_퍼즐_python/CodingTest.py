import string
import sys
from collections import deque

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

def getXYidx(x, y):
    return x * 3 + y

startStr = ""
for _ in range(3):
    startStr += input().rstrip().replace(" ", "")

idx = startStr.find('0')
startX = idx // 3
startY = idx % 3

history = set()
history.add(startStr)
q = deque()
q.append([startStr, 0, startX, startY])
answer = -1

moveX = [1, -1, 0, 0]
moveY = [0, 0, 1, -1]

while q:
    nowStr, count, nowX, nowY = q.popleft()
    if nowStr == '123456780':
        answer = count
        break
    
    for dic in range(4):
        posX = nowX + moveX[dic]
        posY = nowY + moveY[dic]

        if 0 <= posX < 3 and 0 <= posY < 3:
            tempStr = list(nowStr)
            tempStr[getXYidx(nowX, nowY)], tempStr[getXYidx(posX, posY)] = tempStr[getXYidx(posX, posY)], tempStr[getXYidx(nowX, nowY)]
            tempStr = ''.join(tempStr)

            if tempStr not in history:
                history.add(tempStr)
                q.append([tempStr, count + 1, posX, posY])
            
print(answer)