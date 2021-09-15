import string
import sys
from itertools import permutations

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

size = int(input().rstrip()) 
numArr = [i for i in range(1, size + 1)]

for arr in permutations(numArr, size):
    for num in arr:
        print(num, end=' ')
    print("")