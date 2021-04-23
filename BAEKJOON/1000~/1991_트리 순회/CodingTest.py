import string

size = int(input())

def getIndexAlphabet(alpahbet):
    return ord(alpahbet) - ord('A')

def getAlphabetIndex(index):
    alphabet_list = list(string.ascii_uppercase)
    return alphabet_list.index(index)

arr = [[] for _ in range(26)]

for _ in range(size):
    parent, l_child, r_child = map(str, input().split())
    arr[getIndexAlphabet(parent)] = [l_child, r_child]

def preorder(node):    
    if node == '.': 
        return ''

    return node + preorder(arr[getAlphabetIndex(node)][0]) + preorder(arr[getAlphabetIndex(node)][1])

def inorder(node):    
    if node == '.': 
        return ''

    return inorder(arr[getAlphabetIndex(node)][0]) + node + inorder(arr[getAlphabetIndex(node)][1])

def postorder(node):    
    if node == '.': 
        return ''

    return postorder(arr[getAlphabetIndex(node)][0]) + postorder(arr[getAlphabetIndex(node)][1]) + node

print(preorder('A'))
print(inorder('A'))
print(postorder('A'))