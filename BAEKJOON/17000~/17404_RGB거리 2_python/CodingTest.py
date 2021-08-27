import string
import sys
from copy import deepcopy

sys.setrecursionlimit(10**9)
input = sys.stdin.readline
LIMIT = int(1e9)

#n, m = map(int, input().split())
#k = input().rstrip()

size = int(input().rstrip())

houses = []
for _ in range(size):
    houses.append(list(map(int, input().split())))

answer = LIMIT
for color in range(3):
    dpHouses = deepcopy(houses)
    for idx in range(3):
        if color == idx:
            dpHouses[1][idx] = LIMIT
        else:
            dpHouses[1][idx] += dpHouses[0][color]

    for idx in range(2, size):
        dpHouses[idx][0] += min(dpHouses[idx - 1][1], dpHouses[idx - 1][2])
        dpHouses[idx][1] += min(dpHouses[idx - 1][0], dpHouses[idx - 1][2])
        dpHouses[idx][2] += min(dpHouses[idx - 1][1], dpHouses[idx - 1][0])

    for idx in range(3):
        if color != idx:
            answer = min(answer, dpHouses[size - 1][idx])

print(answer)