import string
import sys

input = sys.stdin.readline

collection = ['a', 'e', 'i', 'o', 'u']

def BT(dict, word, arr, L, C, col, con, last):
    pos = len(word)

    if pos == L:
        if word not in dict:
            if col >= 1 and con >= 2:
                print(word)
                dict.add(word)
                return

    for i in range(last, C - (L - (pos + 1))):
        if i >= C: continue
        if arr[i] in collection:
            BT(dict, word + arr[i], arr, L, C, col + 1, con, i + 1)
        else:
            BT(dict, word + arr[i], arr, L, C, col, con + 1, i + 1)

        


L, C = map(int, input().split())
arr = input().rstrip().split(' ')
arr.sort()
dict = set()

BT(dict, '', arr, L, C, 0, 0, 0)