import string
import sys
from collections import Counter

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

x, y, b = map(int, input().split())
matrix = []

max_val = 0
min_val = 256
for _ in range(x):
    matrix += map(int, input().split())

matrix = dict(Counter(matrix))

height = 0
min_time = 100000000000000

for target in range(257):
    target = 256 - target
    A_count = 0
    B_count = 0

    for high in matrix:
        if target < high:
            A_count += matrix[high] * (high - target)
        else:
            B_count += matrix[high] * (target - high)

    if B_count <= A_count + b:
        time = ((A_count * 2) + B_count)

        if min_time > time:
            min_time = time
            higt = target

print(min_time, higt)