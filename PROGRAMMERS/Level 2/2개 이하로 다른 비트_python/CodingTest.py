import string
import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

def solution(numbers):
    answer = []

    for num in numbers:
        #주어진 수를 2진수로 만든다
        binArr = list('0' + bin(num)[2:])
        idx = ''.join(binArr).rfind('0')
        binArr[idx] = '1'

        if num % 2 == 1:    #홀수이면
            binArr[idx+1] = '0'

        answer.append(int('0b'+''.join(binArr), 2))

    return answer

print(solution([5,7]))