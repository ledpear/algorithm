import string
import sys
from collections import deque

def getStr(num):
    if num < 10:
        return str(num)
    else:
        return chr(num + 55)

def solution(n, t, m, p):
    answer = ''
    
    lastIdx = m * t + p

    result = '0'
    num = 1
    while len(result) <= lastIdx:
        nowNum = num
        temp = ''
        while nowNum:
            temp = getStr(nowNum % n) + temp
            nowNum //= n
        
        result += temp
        num += 1

    idx = p - 1
    
    for turn in range(t):
        answer += result[idx]
        idx += m

    return answer

#print(solution(2,4,2,1))
#print(solution(16,16,2,1))
print(solution(16,16,2,2))