from string import digits

import sys
input = sys.stdin.readline

n, m = map(int, input().split())

arr = [''] * (n + 1)
arr_dir = {}

for i in range(1, n + 1):
    arr[i] = input().rstrip()
    arr_dir[arr[i]] = i

for _ in range(m):
    q = input().rstrip()
    if q.isdigit() :
        print(arr[int(q)])
    else:
        print(arr_dir[q])