import string
import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

#입력받은 수를 2진수 배열로 만든다
#입력받은 수를 기준으로 하나씩 늘려가며 숫자를 검사한다
#숫자를 검사할 때 2로 나누면서 진행하며 2개 이상 틀리면 종료한다
#모든 숫자가 1인 2진수라면 자릿수가 달라지지만 아니라면 그럴일이 없다
#때문에 모든 숫자가 1일때를 예외처리하고 나머지는 같은 자릿수에서 비교한다

def solution(numbers):
    answer = []

    for num in numbers:
        #주어진 수를 2진수로 만든다
        binArr = list(bin(num)[2:])
        if '0' in binArr:
            binArr.reverse()
            #0이 하나라도 있으면 반복해서 찾는다
            nowNow = num
            while True:
                wrongCount = 0
                nowNow += 1
                tempNum = nowNow
                result = True

                for binNum in binArr:
                    if int(binNum) != (tempNum % 2):
                        wrongCount += 1
                        if wrongCount > 2:
                            result = False
                            break
                    
                    tempNum //= 2
                
                if result:
                    answer.append(nowNow)
                    break

        else:   #모든 숫자가 1일때
            binArr[0] = '0'
            binArr = ['1'] + binArr
            answer.append(int('0b'+''.join(binArr), 2))

    return answer

print(solution([5,7]))