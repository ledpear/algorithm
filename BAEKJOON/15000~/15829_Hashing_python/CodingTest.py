import string
import sys

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

M = 1234567891

size = int(input().rstrip())
str_input = input().rstrip()

result = 0
for i in range(size):
    num = ord(str_input[i]) - 96
    result += num * pow(31, i)

print(result%M)