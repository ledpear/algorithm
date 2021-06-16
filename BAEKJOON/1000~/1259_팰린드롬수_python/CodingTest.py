import string
import sys

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

while True:
    num = input().rstrip()
    if num == '0':
        break

    right = 0
    left = len(num) - 1
    result = True

    while right <= left:
        if num[right] != num[left]:
            result = False
            break

        right += 1
        left -= 1
    
    if result:
        print('yes')
    else:
        print('no')