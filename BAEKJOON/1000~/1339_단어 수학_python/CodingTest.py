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
    m = {}
    max_val = 0
    max_c = ''

    for j in range(n):
        if max_len[j][i] != ' ':
            if max_len[j][i] in m:
                m[max_len[j][i]] += 1
            else:
                m[max_len[j][i]] = 1

            if m[max_len[j][i]] > max_val:
                
