import string
import sys
from string import ascii_uppercase

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

class oper_tree:
    def __init__(self, leftnode, rightnode, val):
        self.leftnode = leftnode
        self.rightnode = rightnode
        self.val = val

    

str_input = input().rstrip()
answer = ""
stack = []
oper = ['+', '-', '*', '/']

for c in str_input:
    if c in ascii_uppercase:
        answer += c
    elif c == '(':
        stack.append(c)
    elif c == ')':
        while stack and stack[-1] != '(':
            answer += stack.pop()
        stack.pop()
    elif c == '+' or c == '-':
        while stack and stack[-1] != '(':
            answer += stack.pop()
        stack.append(c)
    elif c == '*' or c == '/':
        while stack and (stack[-1] == '*' or stack[-1] == '/'):
            answer += stack.pop()
        stack.append(c)

while stack:
    answer += stack.pop()

node_stack = []
for c in answer:
    if c in ascii_uppercase:
        node_stack.append(c)
    elif c in oper:
        left = node_stack[-2]
        right = node_stack[-1]
        new_node = oper_tree(left, right, c)
        node_stack.pop()
        node_stack.pop()
        node_stack.append(new_node)

print(answer)