import string
import sys
import copy

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

num_size, sum_size = map(int, input().split())

arr = list(map(int, input().split()))
arr = [0] + arr

for i in range(2, num_size + 1):
    arr[i] += arr[i - 1]

for _ in range(sum_size):
    start, end = map(int, input().split())
    print(arr[end] - arr[start - 1])
        