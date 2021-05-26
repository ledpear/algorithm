import string
import sys

input = sys.stdin.readline

n = input().rstrip()
#n, m = map(int, input().split())

arr = []
max_len = 0

for i in range(n):
    arr.append(input().rstrip())
    size = len(arr[i])
    if size > max_len:
        max_len = size

word_arr = []

for word in arr:
    i = max_len - len(word)
    temp_arr = [' '] * max_len

    for c in word:
        temp_arr[i] = c

    word_arr.append(temp_arr)

for i in range(max_len):
