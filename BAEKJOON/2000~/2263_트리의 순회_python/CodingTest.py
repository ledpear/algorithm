import sys
sys.setrecursionlimit(10**9)

input = sys.stdin.readline

class oper_tree:
    def __init__(self, left, right, val):
        self.left = left
        self.right = right
        self.val = val

size = int(input().rstrip())
in_order = list(map(int, input().split()))
post_order = list(map(int, input().split()))

in_order_pos = [0] * (size + 1)
for i in range(size):
    in_order_pos[in_order[i]] = i

def makeTree(in_start, in_end, post_start, post_end):
    if in_start > in_end or post_start > post_end:
        return None

    root = post_order[post_end]
    pos = in_order_pos[root]

    left_size = pos - in_start
    right_size = in_end - pos

    left = None
    right = None

    if pos - 1 >= 0 :
        left = makeTree(in_start, pos - 1, post_start, post_start + left_size - 1)

    if pos + 1 < size:
        right = makeTree(pos + 1, in_end, post_end - right_size, post_end - 1)

    return oper_tree(left, right, root)

def printTree(operTree):
    if operTree == None:
        return
    else:
        print(operTree.val, end = " ")

    printTree(operTree.left)
    printTree(operTree.right)

tempTree = makeTree(0, size - 1, 0, size - 1)
printTree(tempTree)