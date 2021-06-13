import string
import sys

input = sys.stdin.readline

n, k = map(int, input().split())

n_arr = []
k_arr = []

for _ in range(n):
    n_arr.append(list(map(int, input().split())))
for _ in range(k):
    k_arr.append(int(input().rstrip()))

n_arr.sort()
k_arr.sort()

print(n_arr)