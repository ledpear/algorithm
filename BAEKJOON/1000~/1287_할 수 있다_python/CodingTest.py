import string
import sys

input = sys.stdin.readline
OPER = '+-*/'

class oper_tree:
    def __init__(self, leftnode, rightnode, val):
        self.leftnode = leftnode
        self.rightnode = rightnode
        self.val = val

    def isTerminalNode(self):
        if self.leftnode == None and self.rightnode == None:
            return True
        else:
            return False

def tree_cal(opertree):
    if opertree.isTerminalNode():
        return int(opertree.val)
    if opertree.leftnode.isTerminalNode() and opertree.rightnode.isTerminalNode():
        return str_cal(opertree.leftnode.val, opertree.rightnode.val, opertree.val)
    elif opertree.leftnode.isTerminalNode():
        return str_cal(opertree.leftnode.val, tree_cal(opertree.rightnode), opertree.val)
    elif opertree.rightnode.isTerminalNode():
        return str_cal(tree_cal(opertree.leftnode), opertree.rightnode.val, opertree.val)
    else:
        return str_cal(tree_cal(opertree.leftnode), tree_cal(opertree.rightnode), opertree.val)

        
def str_cal(leftnode, rightnode, oper):
    if oper == '+':
        result = int(leftnode) + int(rightnode)
    elif oper == '-':
        result = int(leftnode) - int(rightnode)
    elif oper == '*':
        result = int(int(leftnode) * int(rightnode))
    elif oper == '/':
        result = int(int(leftnode) // int(rightnode))

    return result


equation = input().rstrip()

#정상적인 수식인지 판단
#괄호가 정상적인지 판단 - 완료
#연산자가 연속으로 오는지 확인 - 완료
#( 다음에 연산자가 올때 - 완료
#) 전에 연산자가 올때 - 완료
#처음이나 마지막에 연산자가 올때 

if equation[0] in OPER or equation[-1] in OPER:
    print("ROCK")
else:
    result = True
    oper_check = False

    parentheses_stack = []
    for index in range(len(equation)):
        if equation[index] in OPER:
            if not oper_check:
                oper_check = True
            else:
                result = False
                break
        else:
            oper_check = False
            if equation[index] == '(':
                parentheses_stack.append('(')
                if index < len(equation) - 1:
                    if equation[index] in OPER:
                        result = False
                        break
            elif equation[index] == ')':
                if parentheses_stack:
                    parentheses_stack.pop()
                else:
                    result = False
                    break
                if index > 0:
                    if equation[index - 1] in OPER:
                        result = False
                        break
                
    if parentheses_stack:
        result = False

    if not result : 
        print("ROCK")
    else:
        postfix = []
        str_num = ''
        oper_stack = []

        for c in equation:
            if c in string.digits:
                str_num += c
            else:
                if str_num != '':
                    postfix.append(str_num)
                    str_num = ''
                    
                if c == '(':
                    oper_stack.append(c)
                elif c == ')':
                    while oper_stack and oper_stack[-1] != '(':
                        postfix.append(oper_stack.pop())
                    oper_stack.pop()
                elif c == '+' or c == '-':
                    while oper_stack and oper_stack[-1] != '(':
                        postfix.append(oper_stack.pop())
                    oper_stack.append(c)
                elif c == '*' or c == '/':
                    while oper_stack and (oper_stack[-1] == '*' or oper_stack[-1] == '/'):
                        postfix.append(oper_stack.pop())
                    oper_stack.append(c)
                    
        if str_num != '':
                    postfix.append(str_num)
                    str_num = ''

        while oper_stack:
            postfix.append(oper_stack.pop())

        node_stack = []

        for c in postfix:
            if c.isdigit():
                node_stack.append(oper_tree(None, None, c))
            else:
                if len(node_stack) < 2:
                    result = False
                    break
                left = node_stack[-2]
                right = node_stack[-1]
                new_node = oper_tree(left, right, c)
                node_stack.pop()
                node_stack.pop()
                node_stack.append(new_node)

        if result and len(node_stack) == 1:
            print(tree_cal(node_stack[0]))
        else:
            print("ROCK")