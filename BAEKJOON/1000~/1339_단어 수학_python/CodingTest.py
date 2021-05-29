import string
import sys
import heapq

#input = sys.stdin.readline

n = int(input().rstrip())
words = dict()

for _ in range(n):
    word = input()
    size = len(word)

    k = size - 1
    for c in word:
        if c in words:
            words[c] += pow(10,k)
        else:
            words[c] = pow(10,k)
        k -= 1

values = list(words.values())

values.sort(reverse=True)

k = 9
answer = 0
for value in values:
    answer += value * k
    k -= 1

print(answer)