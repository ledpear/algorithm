import copy
from collections import deque

def parser(expression):
    oper = ['*', '+', '-']
    num = ''
    nums = deque([])
    opers = deque([])

    for c in expression:
        if c in oper:
            nums.append(int(num))
            opers.append(c)
            num = ''
        else:
            num += c

    nums.append(int(num))

    return nums, opers

def sol_max(nums, opers, used, result):
    oper = ['*', '+', '-']

    size = len(opers)

    if size == 0:
        val = abs(nums.pop())
        if val > result[0] :
            result[0] = val
        return

    for o in range(3):
        if not used[o]:
            copy_nums = copy.deepcopy(nums)
            copy_opers = copy.deepcopy(opers)

            new_nums = deque([])
            new_opers = deque([])
            
            new_nums.append(copy_nums.popleft())

            for i in range(size):
                now_oper = copy_opers.popleft()
                #new_nums.append(copy_nums.popleft())

                if now_oper == oper[o]:
                    str_num1 = str(new_nums.pop())
                    str_num2 = str(copy_nums.popleft())      
                    new_nums.append(int(eval(str_num1 + now_oper + str_num2)))
                else:
                    new_nums.append(copy_nums.popleft())
                    new_opers.append(now_oper)
            
            used[o] = True
            sol_max(new_nums, new_opers, used, result)
            used[o] = False




def solution(expression):
    answer = 0
    used = [False, False, False]
    result = [0]
    
    nums, opers = parser(expression)
    sol_max(nums, opers, used, result)
    answer = result[0]

    return answer

solution("100-200*300-500+20")