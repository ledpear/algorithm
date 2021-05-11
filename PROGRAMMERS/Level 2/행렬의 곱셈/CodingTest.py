import numpy as np

def solution(arr1, arr2):

    a = np.array(arr1)
    b = np.array(arr2)

    answer = np.dot(a,b)

    return answer

arr1 = [[2, 3, 2], [4, 2, 4], [3, 1, 4]]
arr2 = [[5, 4, 3], [2, 4, 1], [3, 1, 1]]	
print(solution(arr1, arr2))