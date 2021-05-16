def blockCheck(x, y, board):
    if board[x][y] != ' ' and board[x][y] == board[x][y+1] and board[x][y] == board[x+1][y] and board[x][y] == board[x+1][y+1]:
        return True
    else:
        return False

def blockCrush(x, y, board, answer):
    pos_arr = [[x,y],[x+1,y],[x,y+1],[x+1,y+1]]

    for pos in pos_arr:
        pos_x = pos[0]
        pos_y = pos[1]

        if board[pos_x][pos_y] != ' ':
            answer += 1
            board[pos_x][pos_y] = ' '
            
    return answer

def boardSetting(m, n, board) :
    new_board = [[' '] * n for i in range(m)]

    for y in range(n):
        new_x = m - 1
        
        for i in range(m):
            
            x = m - i - 1
            if board[x][y] != ' ' :
                new_board[new_x][y] = board[x][y]
                new_x -= 1

    return new_board

def solution(m, n, board):
    for i in range(m):
        board[i] = list(board[i])


    answer = 0
    crush_pos = []
    while True:
        crush_pos.clear()
        for x in range(m - 1):
            for y in range(n - 1):
                if blockCheck(x, y, board):
                    crush_pos.append([x, y])

        if not crush_pos:
            break

        for crush in crush_pos:
            answer = blockCrush(crush[0], crush[1], board, answer)

        board = boardSetting(m, n, board)
        

    return answer

solution(4, 5, 	["CCBDE", "AAADE", "AAABF", "CCBBF"])