def solution(n):
    answer = 1

    dp = list(range(1, n + 1))
    arr = list(range(1, n + 1))
    last = n

    for i in range(1, n -1):
        save = [0] * n

        if i >= last: break
        last_temp = i
        for j in range(i, last):
            save[j] = dp[j - 1] + arr[j]
            
            if save[j] == n : answer += 1
            elif save[j] > n : break

            last_temp += 1

        dp = save
        last = last_temp

    return answer

print(solution(15))