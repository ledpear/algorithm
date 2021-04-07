def solution(nums):
    answer = 0

    num_size = len(nums)
    num_max = num_size * 1000

    decimal_arr = [0] * (num_max + 1)
    decimal_arr[0] = 1
    decimal_arr[1] = 1

    #소수 구하기
    for i in range(2, num_max + 1):
        if decimal_arr[i] == 0:
            j = 2
            while True:
                temp = i * j
                if temp > num_max :
                    break
                else :
                    decimal_arr[temp] = 1
                    j += 1

    #숫자 조합
    for a in range(0, num_size - 2):
        for b in range(a+1, num_size - 1):
            for c in range(b+1, num_size):
                temp = nums[a] + nums[b] + nums[c]
                if decimal_arr[temp] == 0:
                    answer += 1

    return answer

print(solution([1,2,7,6,4]))