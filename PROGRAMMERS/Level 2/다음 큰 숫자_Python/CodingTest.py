def BinaryCount(n):
    count = 0
    while n > 0:
        if n % 2 == 1:
            count += 1
        n = int(n / 2)
    return count
        

def solution(n):
    input_count = BinaryCount(n)
    answer = n + 1

    while True:
        answer_count = BinaryCount(answer)
        if input_count == answer_count :
            break
        else:
            answer += 1

    return answer

print(solution(15))