import string
import sys

input = sys.stdin.readline

size = input().rstrip()

arr = list(map(int, input().split()))

b, c = map(int, input().split())

answer = 0

for num in arr:
    answer += 1
    if num <= b:
        continue

    num -= b

    answer += int(num / c)
    if num % c != 0:
        answer += 1

print(answer)