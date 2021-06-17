import string
import sys

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

numArr = [False] * 21

testcase = int(input().rstrip())

for t in range(testcase):
    cmd = list(map(str, input().split()))
    
    if len(cmd) == 1:
        if cmd[0] == "all":
            numArr = [True] * 21
        elif cmd[0] == "empty":
            numArr = [False] * 21
    else:
        num = int(cmd[1])
        if cmd[0] == "add":
            numArr[num] = True
        elif cmd[0] == "check":
            if numArr[num]:
                print(1)
            else:
                print(0)
        elif cmd[0] == "remove":
            numArr[num] = False
        elif cmd[0] == "toggle":
            numArr[num] = not numArr[num]