def solution(s):
    answer = []
    round = 0
    zero_count = 0

    while s != '1':
        temp = ''
        
        for c in s:
            if c == '1':
                temp += '1'
        
        zero_count += len(s) - len(temp)
        round += 1

        s = bin(len(temp))[2:]

    answer = [round, zero_count]
    return answer

print(solution("110010101001"))
print(solution("01110"))
print(solution("1111111"))