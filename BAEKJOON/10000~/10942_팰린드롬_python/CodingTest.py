import string
import sys
input = sys.stdin.readline

def palindrome_check(S, E, palindrome, arr, size):
    while True:
        if S < 0 or E >= size:
            break

        if arr[S] == arr[E]:
            palindrome[S][E] = 1
            S -= 1
            E += 1
        else:
            break

N = int(input().rstrip())
arr = input().rstrip().split(' ')

palindrome = [[0]*N for _ in range(N)]

for i in range(N):
    palindrome_check(i, i, palindrome, arr, N)
    if i < N - 1:
        palindrome_check(i, i + 1, palindrome, arr, N)

M = int(input().rstrip())

for _ in range(M):
    S, E = map(int, input().split())
    print(palindrome[S-1][E-1])
    