import string
import sys

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

size, target_x, target_y = map(int, input().split())
size = int(pow(2, size))

answer = 0

temp_x = (target_x // 2) * 2
temp_y = (target_y // 2) * 2


def search(size, x, y, start):
    global answer

    if size == 2:
        for i in range(2):
            for j in range(2):
                if target_x == (x + i) and target_y == (y + j):
                    return start
                start += 1

    else:
        quarter_size = (size * size) // 4
        half_size = int(size / 2)

        val = start
        pos_x = x
        pos_y = y

        if target_y >= y + half_size:
            val += quarter_size
            pos_y += half_size
        if target_x >= x + half_size:
            val += (quarter_size * 2)
            pos_x += half_size

        return search(half_size, pos_x, pos_y, val)


print(search(size, 0, 0, 0))