import string
from collections import deque
import sys

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

testcase = int(input().rstrip())

def cmd_D(num):
    return int((num * 2) % 10000)

def cmd_S(num):
    if num == 0:
        return 9999
    else:
        return num - 1
    
def cmd_L(num):
    return int(num % 1000 * 10 + num / 1000)

def cmd_R(num):
    return int(num % 10 * 1000 + num // 10)

for _ in range(testcase):
    start, target = map(int, input().split())
    visit = [False] * 10000

    visit[start] = True
    queue = deque()
    queue.append([start, ''])

    while queue:
        now_num, now_cmd = queue.popleft()

        temp_num = cmd_D(now_num)
        if temp_num == target:
            print(now_cmd + 'D')
            break
        if not visit[temp_num]:
            visit[temp_num] = True
            queue.append([temp_num, now_cmd + 'D'])

        temp_num = cmd_S(now_num)
        if temp_num == target:
            print(now_cmd + 'S')
            break
        if not visit[temp_num]:
            visit[temp_num] = True
            queue.append([temp_num, now_cmd + 'S'])

        temp_num = cmd_L(now_num)
        if temp_num == target:
            print(now_cmd + 'L')
            break
        if not visit[temp_num]:
            visit[temp_num] = True
            queue.append([temp_num, now_cmd + 'L'])

        temp_num = cmd_R(now_num)
        if temp_num == target:
            print(now_cmd + 'R')
            break
        if not visit[temp_num]:
            visit[temp_num] = True
            queue.append([temp_num, now_cmd + 'R'])
