import string
import sys
import bisect as bs

input = sys.stdin.readline

minVal = 500001
result = 0
vaild_num = [True] * 10

target_int = int(input().rstrip())
target_str = str(target_int)

target_arr = list(map(int, list(target_str)))
target_size = len(target_arr)

error_size = int(input().rstrip())
error_button = []
if error_size > 0:
    error_button = input().split()


buttons = []

minVal = abs(target_int - 100)

for i in range(1000001):
    num = str(i)
    p = False

    for n in num:
        if n in error_button:
            p = True
            break
    
    if not p:
        minVal = min(minVal, (abs(target_int - i) + len(num)))


print(minVal)