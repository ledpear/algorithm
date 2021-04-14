def solution(dirs):
    answer = 0

    matrixX = [[0]*11 for _ in range(0, 11)]
    matrixY = [[0]*11 for _ in range(0, 11)]

    posX = 5
    posY = 5

    moveX = [1, 0, -1, 0]
    moveY = [0, 1, 0, -1]

    dir = 0
    for c in dirs:
        if c == 'R' :
            dir = 0
        elif c == 'D' :
            dir = 1
        elif c == 'L' :
            dir = 2
        elif c == 'U' :
            dir = 3

        targetX = posX + moveX[dir]
        targetY = posY + moveY[dir]

        if targetX >= 0 and targetX <= 10 and targetY >= 0 and targetY <= 10:
            if dir == 0 or dir == 2:
                targetMatrix = matrixX
            else:
                targetMatrix = matrixY

            edgeX = min(posX, targetX)
            edgeY = min(posY, targetY)

            if targetMatrix[edgeX][edgeY] == 0:
                answer += 1
                targetMatrix[edgeX][edgeY] = 1

            posX = targetX
            posY = targetY

    return answer


dirs = "ULURRDLLU"
dirs = "LULLLLLLU"
print(solution(dirs))