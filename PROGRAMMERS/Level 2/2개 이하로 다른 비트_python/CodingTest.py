import string
import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

def solution(numbers):
    answer = []

    for num in numbers:
        #주어진 수를 2진수로 만든다
        binArr = list(bin(num)[2:])
        if '0' not in binArr:
            binArr[0] = '0'
            binArr = ['1'] + binArr
        else:
            size = len(binArr)
            for reverseIdx in range(1, size + 1):
                idx = size - reverseIdx
                if binArr[idx] == '0':
                    binArr[idx] = '1'
                    break
        
        answer.append(int('0b'+''.join(binArr), 2))

    return answer

print(solution([5,7]))