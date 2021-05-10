def solution(arr1, arr2):
    answer = []

    x1 = len(arr1)
    y1 = len(arr1[0])

    x2 = len(arr2)
    y2 = len(arr2[0])

    for i in range(x1):
        temp = []
        for j in range(y2):
            num = 0
            for k in range(x2):
                num += arr1[i][k] * arr2[k][j]
            temp.append(num)
        answer.append(temp)

    return answer

arr1 = [[2, 3, 2], [4, 2, 4], [3, 1, 4]]
arr2 = [[5, 4, 3], [2, 4, 1], [3, 1, 1]]	
print(solution(arr1, arr2))