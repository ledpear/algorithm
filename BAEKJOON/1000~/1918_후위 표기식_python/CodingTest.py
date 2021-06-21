import string
import sys

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

input = input().rstrip()
#괄호안에 있는건 재귀로 돌리고
#연산자 좌우로 트리생성
#괄호 체크를 하기위해 스택으로 판단
#괄호 스택이 0일때 연산자를 만나면 루트 노드 생성됨

oper = ['+', '-', '*', '/']
class node:
    def __init__(self, val):
        self.val = val
        self.leftnode = None
        self.rightnode = None

    def __init__(self, val, leftnode, rightnode):
        self.val = val
        self.leftnode = leftnode
        self.rightnode = rightnode

    def isTerminal(self):
        if self.leftnode == None and self.rightnode == None:
            return True
        else:
            return False

    def setLeftNode(self, leftnode):
        self.leftnode = leftnode

    def setrightNode(self, rightnode):
        self.rightnode = rightnode

def makeTree(input):
    if len(input) == 1:
        return node(input, None, None)
    stack = []
    left = ''
    for i in range(len(input)):
        if input[i] == '(':
            stack.append(i)
        elif input[i] == ')':
            stack.pop()
        elif input[i] in oper and not stack:
            leftnode = makeTree(input[:i])
            rightnode = makeTree(input[i+1:])
            return node(input[i], leftnode, rightnode)

    return makeTree(input[1:-1])

tree = makeTree(input)
print("test")