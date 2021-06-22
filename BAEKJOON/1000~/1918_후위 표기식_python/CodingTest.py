import string
import sys

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

input = input().rstrip()

second_oper = ['+', '-']
first_oper = ['*', '/']

answer = ''
stack = []

for c in input:
    if 'A' <= c <= 'Z':
        answer += c
    elif c == '(':
        stack.append(c)
    elif c == ')':
        while stack and stack[-1] != '(':
            answer += stack.pop()
        stack.pop()
    elif c in second_oper:
        while stack and stack[-1] != '(':
            answer += stack.pop()
        stack.append(c)
    elif c in first_oper:
        while stack and stack[-1] in first_oper:
            answer += stack.pop()
        stack.append(c)

while stack:
    answer += stack.pop()

print(answer)