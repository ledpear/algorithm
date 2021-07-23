import string
import sys
from copy import deepcopy

input = sys.stdin.readline

size = int(input())

def hanoi(size, a, b, c):
    if size == 1:
        print(a, c)
    else:
        hanoi(size - 1, a, c, b)
        print(a, c)
        hanoi(size - 1, b, a, c)

count = 1

for i in range(size - 1):
    count = count * 2 + 1
print(count)
hanoi(size, 1, 2, 3)