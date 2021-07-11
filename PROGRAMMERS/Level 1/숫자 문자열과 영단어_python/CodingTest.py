import string 

def solution(s):
    answer = ''
    num_list = list(string.digits)
    dic = {'zero':0, 'one':1, 'two':2, 'three':3, 'four':4, 'five':5, 'six':6, 'seven':7, 'eight':8, 'nine':9}
    temp = ''

    for c in s:        
        if c not in num_list:
            temp += c
            if temp in dic:
                answer += str(dic[temp])
                temp = ''
        else:
            answer += c

    return int(answer)

print(solution("one4seveneight"))