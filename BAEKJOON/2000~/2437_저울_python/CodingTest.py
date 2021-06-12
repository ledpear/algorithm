import string
import sys

input = sys.stdin.readline

size = int(input().rstrip())

arr = list(map(int, input().split()))

arr.sort()

sumVal = 0

for i in range(size):
    if sumVal + 1 < arr[i]:
        sumVal += 1
        break
    
    sumVal += arr[i]


print(sumVal)