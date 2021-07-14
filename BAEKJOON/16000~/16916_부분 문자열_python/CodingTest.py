import string
import sys

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

input_str = input().rstrip()
input_substr = input().rstrip()

def check(pos):
    result = True
    for index in range(len(input_substr)):
        if input_str[pos - index] != input_substr[len(input_substr) - 1 - index]:
            result = False

    return result

result = False
for index in range(len(input_substr) - 1, len(input_str)):
    if input_str[index] == input_substr[-1]:
        if check(index):
            result = True
            break

if result:
    print(1)
else:
    print(0)