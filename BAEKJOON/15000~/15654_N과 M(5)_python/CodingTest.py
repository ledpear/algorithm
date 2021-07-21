import string
import sys

input = sys.stdin.readline

arrSize, permutationSize = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

def permutationsPrint(arr, size, result, used):
    if len(result) == size:
        for num in result:
            print(num, end=' ')
        print()
    
    for index in range(len(arr)):
        if not used[index]:
            used[index] = True
            result.append(arr[index])
            permutationsPrint(arr, size, result, used)
            result.pop()
            used[index] = False

permutationsPrint(arr, permutationSize, [], [False] * arrSize)