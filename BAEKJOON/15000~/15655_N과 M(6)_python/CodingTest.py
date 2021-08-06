import string
import sys
import itertools

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

arrSize, permutationSize = map(int, input().split())
numArr = list(map(int, input().split()))
numArr.sort()

for result in itertools.combinations(numArr, permutationSize):
    for num in result:
        print(num, end=' ')

    print()