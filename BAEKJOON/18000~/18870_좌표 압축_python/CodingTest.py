import string
import sys
from copy import deepcopy

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

size = int(input().rstrip())
original = map(int, input().split())
output_list = list(deepcopy(original))
arr = set(original)
arr = list(arr)
arr.sort()

dicionary = {}
for i in range(len(arr)):
    dicionary[arr[i]] = i

for i in range(size):
    print(dicionary[output_list[i]], end=' ')

