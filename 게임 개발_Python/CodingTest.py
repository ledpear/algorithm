n = 4
m = 4
pos_x = 1
pos_y = 1

dir = 0 # 0 : 북, 1 : 동, 2 : 남, 3 : 서

game_map = [[1,1,1,1], [1,0,0,1], [1,1,0,1], [1,1,1,1]]
bool_map = [[0,0,0,0], [0,0,0,0], [0,0,0,0], [0,0,0,0]]

bool_map[pos_y][pos_x] = 1

count = 0
score = 1

while True:
    dir -= 1
    if dir < 0 : dir = 3

    bResult = False

    if dir == 0 :
        if pos_y - 1 >= 0 :
            if game_map[pos_y - 1][pos_x] == 0 and bool_map[pos_y - 1][pos_x] == 0 :
                pos_y -= 1;
                bool_map[pos_y][pos_x] = 1
                bResult = True
                score += 1
    elif dir == 1 :
        if pos_x + 1 < m :
            if game_map[pos_y][pos_x + 1] == 0 and bool_map[pos_y][pos_x + 1] == 0 :
                pos_x += 1;
                bool_map[pos_y][pos_x] = 1
                bResult = True
                score += 1
    elif dir == 2 :
        if pos_y + 1 < n :
            if game_map[pos_y + 1][pos_x] == 0 and bool_map[pos_y + 1][pos_x] == 0 :
                pos_y += 1;
                bool_map[pos_y][pos_x] = 1
                bResult = True
                score += 1
    elif dir == 3 :
        if pos_x - 1 >= 0 :
            if game_map[pos_y][pos_x - 1] == 0 and bool_map[pos_y][pos_x - 1] == 0 :
                pos_x -= 1;
                bool_map[pos_y][pos_x] = 1
                bResult = True
                score += 1

    if bResult :
        count = 0
    else :
        count += 1

    if count == 4 :
        if dir == 0 :
            if pos_y + 1 < n :
                if game_map[pos_y + 1][pos_x] == 0 :
                    pos_y += 1
                    count = 0
                else :
                    break
            else :
                break
        elif dir == 1 :
            if pos_x - 1 >= 0 :
                if game_map[pos_y][pos_x - 1] == 0 :
                    pos_x -= 1
                    count = 0
                else :
                    break
            else :
                break
        elif dir == 2 :
            if pos_y - 1 >= 0 :
                if game_map[pos_y - 1][pos_x] == 0 :
                    pos_y -= 1
                    count = 0
                else :
                    break
            else :
                break
        elif dir == 3 :
            if pos_x + 1 < m :
                if game_map[pos_y][pos_x + 1] == 0 :
                    pos_x += 1
                    count = 0
                else :
                    break
            else :
                break

print(score)