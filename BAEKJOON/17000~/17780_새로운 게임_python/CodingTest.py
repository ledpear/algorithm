import string
import sys
from copy import deepcopy

input = sys.stdin.readline

def Reverse(dir):

    if dir == 1:
        return 2

    elif dir == 2:
        return 1

    elif dir == 3:
        return 4

    elif dir == 4:
        return 3

#k = input().rstrip()
map_size, piece_size = map(int, input().split())

move_x = [0, 0, 0, -1, 1]
move_y = [0, 1, -1, 0, 0]

#맵 정보, 체스보드 현황, 피스 정보, 피스 현황
#로테이션을 했을 경우 위치를 한꺼번에 바꿔야 하므로 합칠때 위치정보를 주소를 복사해서 사용
map_info = []
chessboard = [[[[], 0] for _ in range(map_size)] for _ in range(map_size)]
for _ in range(map_size):
    map_info.append(list(map(int, input().split())))

piece_info = [] #x, y, dir

for i in range(piece_size):
    x, y, dir = map(int, input().split())
    x -= 1
    y -= 1
    piece_info.append([[x, y], dir, True])
    chessboard[x][y][0].append(i)
    chessboard[x][y][1] += 1

count = 1
result = False
#def move(piece_index):

while count <= 1000:
    for piece in piece_info:
        #파란바닥 : 방향을 반대로하고 이동. 단, 이동하는 칸도 파란바닥일 경우 방향만 반대로
        #빨간바닥 : 내부 피스의 방향을 반대로
        #이동 : 그냥 이동과 합치는 경우로 나뉨
        #파란바닥 처리 후 이동 처리
        #빨간바닥 처리 후 이동 처리
        if not piece[2]: continue

        pos, dir, able = piece
        x = pos[0]
        y = pos[1]
        pos_x = x + move_x[dir]
        pos_y = y + move_y[dir]

        #맵 외곽 처리 - 파란 바닥과 동일
        if pos_x < 0 or pos_y < 0 or pos_x >= map_size or pos_y >= map_size:
            piece[1] = Reverse(dir)
            dir = piece[1]

            pos_x = x + move_x[dir]
            pos_y = y + move_y[dir]

            if pos_x < 0 or pos_y < 0 or pos_x >= map_size or pos_y >= map_size or map_info[pos_x][pos_y] == 2:
                continue
                

        #파란 바닥 처리
        if map_info[pos_x][pos_y] == 2 :
            piece[1] = Reverse(dir)
            dir = piece[1]

            pos_x = x + move_x[dir]
            pos_y = y + move_y[dir]

            if pos_x < 0 or pos_y < 0 or pos_x >= map_size or pos_y >= map_size or map_info[pos_x][pos_y] == 2:
                continue

        #빨간 바닥 처리
        if map_info[pos_x][pos_y] == 1 and chessboard[x][y][1] > 1:
            chessboard[x][y][0].reverse()
            piece_info[chessboard[x][y][0][0]][2] = True
            piece_info[chessboard[x][y][0][-1]][2] = False

        #하얀 바닥 처리 : 합치는 경우와 이동만 하는 경우
        if chessboard[pos_x][pos_y][1] >= 1:#합치는 경우
            chessboard[pos_x][pos_y][0].extend(chessboard[x][y][0])
            chessboard[pos_x][pos_y][1] += chessboard[x][y][1]
            if chessboard[pos_x][pos_y][1] >= 4:
                result = True
                break
            #piece_info[chessboard[x][y][0][0]][0] = piece_info[chessboard[pos_x][pos_y][0][0]][0]
            piece_info[chessboard[x][y][0][-1]][0] = piece_info[chessboard[pos_x][pos_y][0][0]][0]
            piece_info[chessboard[x][y][0][0]][2] = False
            chessboard[x][y][0].clear()
            chessboard[x][y][1] = 0
        else:
            chessboard[pos_x][pos_y] = deepcopy(chessboard[x][y])
            piece_info[chessboard[x][y][0][0]][0][0] = pos_x
            piece_info[chessboard[x][y][0][0]][0][1] = pos_y
            chessboard[x][y][0].clear()
            chessboard[x][y][1] = 0

    if result :
        break
    else:
        count += 1

if count <= 1000:
    print(count)
else:
    print(-1)