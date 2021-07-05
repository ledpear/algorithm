import string
import sys
import collections

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

#적록색약이 아닌것과 적록색약인것 2번 BFS를 하면된다.
#입력갯수와 찾은 갯수가 같으면 더이상 할 필요가 없기 때문에 멈춘다.

move_x = [1, -1, 0, 0]
move_y = [0, 0, -1, 1]

size = int(input().rstrip())
count_target = pow(size, 2)
matrix = []

def BFS(x, y, visit, size, target):
    count = 1
    visit[x][y] = True
    queue = collections.deque()
    queue.append([x,y])

    while queue:
        now_x, now_y = queue.popleft()
        for i in range(4):
            pos_x = now_x + move_x[i]
            pos_y = now_y + move_y[i]

            if pos_x >= 0 and pos_y >= 0 and pos_x < size and pos_y < size and not visit[pos_x][pos_y] and matrix[pos_x][pos_y] in target:
                count += 1
                visit[pos_x][pos_y] = True
                queue.append([pos_x, pos_y])

    return count



for _ in range(size):
    matrix.append(list(input().rstrip()))

first_answer = 0
count = 0
visit = [[False] * size for _ in range(size)]
end = False

for x in range(size):
    for y in range(size):
        if not visit[x][y]:
            target = [matrix[x][y]]
            count += BFS(x, y, visit, size, target)
            first_answer += 1

            if count_target == count:
                end = True
                break

    if end:
        break

second_answer = 0
count = 0
visit = [[False] * size for _ in range(size)]
end = False

for x in range(size):
    for y in range(size):
        if not visit[x][y]:
            if matrix[x][y] == 'B':
                target = ['B']
            else:
                target = ['R', 'G']
            count += BFS(x, y, visit, size, target)
            second_answer += 1

            if count_target == count:
                end = True
                break
    if end:
        break

print(first_answer, second_answer)