import string 
from collections import deque

ROOM_SIZE = 5

def Manhattan(points):
    pos1 = points[0]
    pos2 = points[1]

    if 2 < abs(pos1[0] - pos2[0]) + abs(pos1[1] - pos2[1]):
        return True
    else:
        return False

def bfs(room_map, pos):
    q = deque([[pos[0], pos[1], 1]])

    move_x = [1,0,-1,0]
    move_y = [0,1,0,-1]

    while q:
        now_state = q.popleft()
        now_x = now_state[0]
        now_y = now_state[1]
        dist = now_state[2]

        room_map[now_x][now_y] = 'X'

        for dirc in range(4):
            pos_x = now_x + move_x[dirc]
            pos_y = now_y + move_y[dirc]

            if pos_x >= 0 and pos_y >= 0 and pos_x < ROOM_SIZE and pos_y < ROOM_SIZE:
                if room_map[pos_x][pos_y] == 'P':
                    return False
                
                if room_map[pos_x][pos_y] == 'O' and dist < 2:
                    q.append([pos_x, pos_y, dist + 1])

    return True


def distance_check(room_map, p_list):
    #위치가 2이하인지 확인
    #탐색해서 3넘어가면 바로 종료하고
    #그 전에 만나는게 하나라도 있으면 False

    p_size = len(p_list)

#    for i in range(p_size - 1):
#        for j in range(i + 1, p_size):
#            if not Manhattan([p_list[i], p_list[j]]):
#                if not bfs(room_map, p_list[i]):
#                    return 0
    for p in p_list:
        if not bfs(room_map, p):
            return 0

    return 1


def solution(s):
    answer = []
    
    for room in s:
        room_map = []
        p_list = []
        for pos in range(ROOM_SIZE):
            temp_list = []
            for i in range(ROOM_SIZE):
                val = room[pos][i]
                temp_list.append(val)
                if val == 'P':
                    p_list.append([pos, i])
            room_map.append(temp_list)
        
        answer.append(distance_check(room_map, p_list))

    return answer

print(solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]))