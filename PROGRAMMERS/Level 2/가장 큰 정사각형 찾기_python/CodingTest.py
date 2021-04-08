def solution(board):
    
    sizeX = len(board)
    sizeY = len(board[0])
    
    for x in range(1, sizeX):
        for y in range(1, sizeY):
            board[x][y] = min(board[x - 1][y], board[x][y - 1], board[x - 1][y - 1]) + 1

    val_max_list = max(board)
    val_max = max(val_max_list)

    return val_max * val_max

print(solution([0,0,1]))