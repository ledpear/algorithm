import string
import sys

input = sys.stdin.readline

class node:
    def __init__(self, val, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

inputArr = []
rootNode = None
while True:
    try:
        inputNum = int(input().rstrip())
        if rootNode == None:
            rootNode = node(inputNum)
        else:
            nowNode = rootNode
            while True:
                if inputNum < nowNode.val:
                    if nowNode.left == None:
                        nowNode.left = node(inputNum)
                        break
                    else:
                        nowNode = nowNode.left
                else:
                    if nowNode.right == None:
                        nowNode.right = node(inputNum)
                        break
                    else:
                        nowNode = nowNode.right
    except:
        break

def printTree(Node):
    if Node.left != None:
        printTree(Node.left)
    if Node.right != None:
        printTree(Node.right)
    print(Node.val)

printTree(rootNode)