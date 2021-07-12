import string
import sys
from bisect import bisect_left, bisect_right

class Node():
    def __init__(self,data):
        self.prev = None
        self.next = None
        self.data = data
        

def solution(n,k,cmds):
    node_list = [Node(0)]
    deleted_stack = []
    deleted_state = ['O' for _ in range(n)]
    for num in range(1,n):
        prev_num = node_list[num-1]
        cur_num = Node(num)
        prev_num.next = cur_num
        cur_num.prev = prev_num
        node_list.append(cur_num)
    
    cur_node = node_list[k]

    for cmd in cmds:
        command = cmd.split()
        if len(command)>1:
            num = int(command[1])
            command = command[0]
            if command =='D':
                for _ in range(num):
                    cur_node = cur_node.next
            else:
                for _ in range(num):
                    cur_node = cur_node.prev
        else:
            command = command[0]
            if command == 'C':
                prev_num = cur_node.prev
                next_num = cur_node.next
                deleted_stack.append(cur_node)
                deleted_state[cur_node.data] = 'X'
                if next_num != None:
                    next_num.prev = prev_num
                if prev_num != None:
                    prev_num.next = next_num
                    
                if next_num != None:
                    cur_node = next_num
                else:
                    cur_node = prev_num
            else:
                restore_node = deleted_stack.pop()
                prev_num = restore_node.prev
                next_num = restore_node.next
                if prev_num != None:
                    prev_num.next = restore_node
                if next_num != None:
                    next_num.prev = restore_node
                deleted_state[restore_node.data] = 'O'
    answer = ''.join(deleted_state)
    return answer

#print(solution(8,2,["D 2","C","U 3","C","D 4","C","U 2","Z","Z"]))
print(solution(8,2,["D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"]	))