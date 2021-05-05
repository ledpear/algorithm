from sys import stdin

left_str = list(stdin.readline().strip())
right_str = []

size = int(input())

for input_list in stdin:

    if input_list[0] == 'D':
        if right_str:
            left_str.append(right_str.pop())
    elif input_list[0] == 'L':
        if left_str:
            right_str.append(left_str.pop())
    elif input_list[0] == 'B':
        if left_str:
            left_str.pop()
    elif input_list[0] == 'P':
        left_str.append(input_list[2])


print(''.join(left_str + list(reversed(right_str))))