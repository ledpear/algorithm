import string
import sys

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

N = int(input().rstrip())
M = int(input().rstrip())
S = input().rstrip()

count = 0
answer = 0
N = N * 2 + 1

check = 'IO'
i = 0
while i < M:
    if count == 0:
        if S[i] == 'I':
            count = 1
        i += 1
    else:
        if S[i] == check[count%2]:
            count += 1
            i += 1
        else:
            if count >= N:
                answer += 1
                answer += (count - N) // 2
            count = 0
    
if count >= N:
    answer += 1
    answer += (count - N) // 2

print(answer)