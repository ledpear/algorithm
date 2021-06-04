import string
import sys
import bisect as bs

input = sys.stdin.readline

n = int(input().rstrip())

A_input = list(map(int, input().split()))

A_arr = [0] * (n + 1)
for i in range(n):
    A_arr[A_input[i]] = i + 1

B_input = list(map(int, input().split()))
BtoA_arr = [0] * (n + 1)

for i in range(n):
    BtoA_arr[i] = A_arr[B_input[i]]

lis = [0] * 100001
lis_index = 0

for i in range(1, n):
    if lis[lis_index] < BtoA_arr[i]:
        lis_index += 1
        lis[lis_index] = BtoA_arr[i]
    else:
        target = bs.bisect_left(lis[:lis_index], BtoA_arr[i]) - 1
        lis[target] = BtoA_arr[i]

print(lis_index + 1)