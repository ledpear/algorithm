import string
import sys
import bisect as bs

input = sys.stdin.readline

minVal = 500001
result = 0
vaild_num = [True] * 10

def BT(num, buttons, target_int, target_arr, size, pos):
    global minVal, result, vaild_num

    if num == -1 :
        num = 0
    elif len(str(num)) == size:
        diff = abs(target_int - num)
        if diff < minVal:
            minVal = diff
            result = num
        return

    now_num = target_arr[pos]
    if vaild_num[now_num]:
        num = num * 10 + now_num
        BT(num, buttons, target_int, target_arr, size, pos + 1)
    else:
        find_index = bs.bisect_left(buttons, now_num)
        if find_index == 0 or find_index == len(buttons):
            left_val = buttons[0]
            right_val = buttons[-1]
        else:
            left_val = buttons[find_index - 1]
            right_val = buttons[find_index]

        left_diff = abs(now_num - left_val)
        right_diff = abs(now_num - right_val)

        if left_diff < right_diff:
            num = num * 10 + left_val
            BT(num, buttons, target_int, target_arr, size, pos + 1)
        elif left_diff > right_diff:
            num = num * 10 + right_val
            BT(num, buttons, target_int, target_arr, size, pos + 1)
        else:
            BT(num * 10 + left_val, buttons, target_int, target_arr, size, pos + 1)
            BT(num * 10 + right_val, buttons, target_int, target_arr, size, pos + 1)

        

target_int = int(input().rstrip())
target_str = str(target_int)

target_arr = list(map(int, list(target_str)))
target_size = len(target_arr)

error_size = int(input().rstrip())
error_button = list(map(int, input().split()))

buttons = []

minVal = abs(target_int - 100)

if minVal == 0:
    print(0)
elif error_size == 10 :
    print(minVal)
else:
    for i in range(10):
        if i in error_button:
            vaild_num[i] = False
            continue
        buttons.append(i)

    BT(-1, buttons, target_int, target_arr, target_size, 0)

    print(target_size + minVal)