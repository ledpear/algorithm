import string
import sys
from itertools import permutations

input = sys.stdin.readline

arrSize, permutationSize = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

permutationArr = list(permutations(arr, permutationSize))

for permutation in permutationArr:
    for num in permutation:
        print(num, end=' ')
    print()