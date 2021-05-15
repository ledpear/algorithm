def solution(left, right):
    answer = 0

    arr = list(range(left, right + 1))
    size = len(arr)
    arr_val = [1] * size

    for i in range(2, right + 1):
        for j in range(size):
            if arr[j] >= i:
                if arr[j] % i == 0:
                    arr_val[j] += 1

    for i in range(size):
        if arr_val[i] % 2 == 0:
            answer += arr[i]
        else:
            answer -= arr[i]

    return answer

solution(13, 17)