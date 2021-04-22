from collections import deque
import copy

class Marble:
    x : int = None
    y : int = None

move_x = [1, -1, 0, 0]
move_y = [0, 0, 1, -1]

#set입력용 문자열 만들기
def getMarblePos(red_marble, blue_marble):
    result = "red:x" + str(red_marble.x) + "y" + str(red_marble.y) + "blue:x" + str(blue_marble.x) + "y" + str(blue_marble.y)
    return result

#메트릭스 입력
def matrix_input(matrix, size_x, size_y, red_marble, blue_marble, hole_marble):
    for x in range(size_x):
        temp_input = []
        str_input = input()
        for y in range(len(str_input)):
            temp_input.append(str_input[y])

            # 구슬 위치 입력
            if str_input[y] == 'R':
                red_marble.x = x
                red_marble.y = y
                temp_input[y] = '.'
            if str_input[y] == 'B' :
                blue_marble.x = x
                blue_marble.y = y
                temp_input[y] = '.'
            if str_input[y] == 'O' :
                hole_marble.x = x
                hole_marble.y = y
        
        matrix.append(temp_input)

#메트릭스 이동
def matrix_move(matrix, move_marble, dir):
    marble_x = move_marble.x
    marble_y = move_marble.y

    while True:
        pos_x = marble_x + move_x[dir]
        pos_y = marble_y + move_y[dir]

        if matrix[pos_x][pos_y] == '.':
            marble_x = pos_x
            marble_y = pos_y
        elif matrix[pos_x][pos_y] == '#':
            move_marble.x = marble_x
            move_marble.y = marble_y
            break
        elif matrix[pos_x][pos_y] == 'O':
            return True

    return False

#어떤 구슬이 먼저 이동할지 판단
def red_marble_first(red_marble, blue_marble, dir):
    if dir == 0:
        return red_marble.x > blue_marble.x
    elif dir == 1 :
        return red_marble.x < blue_marble.x
    elif dir == 2 :
        return red_marble.y > blue_marble.y
    elif dir == 3 :
        return red_marble.y < blue_marble.y

size_x, size_y = map(int, input().split())
matrix = []

red_marble = Marble()
blue_marble = Marble()
hole_marble = Marble()

#데이터 입력
matrix_input(matrix, size_x, size_y, red_marble, blue_marble, hole_marble)

#큐 구현
answer = -1
dq = deque()
count = 0
dq.append([red_marble, blue_marble, count])
pos_set = set()
pos_set.add(getMarblePos(red_marble, blue_marble))

while dq:
    item = dq.popleft()
    red_pos = copy.deepcopy(item[0])
    blue_pos = copy.deepcopy(item[1])
    count = item[2]

    if count >= 10:
        break

    result = False

    for dir in range(4):
        red_move = copy.deepcopy(red_pos)
        blue_move = copy.deepcopy(blue_pos)

        red_result = False
        blue_result = False

        if red_marble_first(red_pos, blue_pos, dir):
            #레드 이동 및 결과 판정
            if matrix_move(matrix, red_move, dir):
                red_result = True
            #블루 이동 및 실패판정 - 레드에서 들아기지 않았는데 블루가 들어가면안됨
            if matrix_move(matrix, blue_move, dir):
                blue_result = True
                continue
            #겹침 판단
            if red_move.x == blue_move.x and red_move.y == blue_move.y:
                blue_move.x -= move_x[dir]
                blue_move.y -= move_y[dir]
        else:
            #블루 이동 및 실패판정 - 레드에서 들아기지 않았는데 블루가 들어가면안됨
            if matrix_move(matrix, blue_move, dir):
                blue_result = True
                continue
            #레드 이동 및 결과 판정
            if matrix_move(matrix, red_move, dir):
                red_result = True
            
            #겹침 판단
            if red_move.x == blue_move.x and red_move.y == blue_move.y:
                red_move.x -= move_x[dir]
                red_move.y -= move_y[dir]

        #결과 판단
        if red_result == True and blue_result == False :
            result = True
            answer = count + 1
            break

        #이미 움직였던 위치가 아니라면 추가
        str_pos = getMarblePos(red_move, blue_move)
        if str_pos not in pos_set:
            pos_set.add(str_pos)
            dq.append([red_move, blue_move, count + 1])

    if result :
        break

print(answer)