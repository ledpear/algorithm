import string
import sys
import copy

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

num_size, change_size, sum_size = map(int, input().split())

arr = []
for _ in range(num_size):
    arr.append(int(input().rstrip()))

sum_arr = copy.deepcopy(arr)

for i in range(1, num_size):
    sum_arr[i] += sum_arr[i - 1]

total_size = change_size + sum_size
for _ in range(total_size):
    a, b, c = map(int, input().split())
    if a == 1:
        diff = c - arr[b-1]
        for i in range(b - 1, num_size):
            sum_arr[i] += diff
    elif a == 2:
        print(sum_arr[c - 1] - sum_arr[b - 2])