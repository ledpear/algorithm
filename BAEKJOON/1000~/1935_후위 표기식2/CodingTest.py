import string
import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

size = int(input().rstrip())
formula = input().rstrip()
wordNum = [0] * size

for idx in range(size):
    wordNum[idx] = int(input().rstrip())

def getVal(word):
    return wordNum[ord(word) - ord('A')]

stack = []

for word in formula:
    if word in string.ascii_uppercase:
        stack.append(getVal(word))
    else:
        numB = stack.pop()
        numA = stack.pop()

        if word == '+':
            numA += numB
        elif word == '-':
            numA -= numB
        elif word == '*':
            numA *= numB
        elif word == '/':
            numA /= numB

        stack.append(numA)

print("{:.2f}".format(stack[0]))