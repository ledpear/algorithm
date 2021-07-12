import string
import sys
from bisect import bisect_left, bisect_right

class Node():
    def __init__(self,val):
        self.pre = None
        self.post = None
        self.val = val
        

def solution(n,k,cmds):
    arr = ['O' for _ in range(n)]
    now_pos = k
    stack = []

    for cmd in cmds:
        cmd = cmd.split()
        if len(cmd) > 1:
            move = int(cmd[1])
            cmd = cmd[0]
            count = 0

            if cmd == 'D':
                while count != move:
                    now_pos += 1
                    if arr[now_pos] == 'O':
                        count += 1
            else:
                while count != move:
                    now_pos -= 1
                    if arr[now_pos] == 'O':
                        count += 1

        else:
            cmd = cmd[0]
            if cmd == 'C':
                arr[now_pos] = 'X'
                stack.append(now_pos)
                
                move_pos = now_pos + 1
                while move_pos < n:
                    if arr[move_pos] == 'X':
                        move_pos += 1
                    else:
                        break
                if move_pos == n:
                    while arr[now_pos] == 'X':
                        now_pos -= 1
                else:
                    now_pos = move_pos
            else:
                arr[stack[-1]] = 'O'
                stack.pop()

    return ''.join(arr)

#print(solution(8,2,["D 2","C","U 3","C","D 4","C","U 2","Z","Z"]))
print(solution(8,2,["D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"]	))