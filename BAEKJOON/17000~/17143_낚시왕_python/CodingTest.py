import string
import sys
import heapq
from types import resolve_bases

moveX = [0, -1, 1, 0, 0]
moveY = [0, 0, 0, 1, -1]

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

boardSizeX, boardSizeY, sharkTotalCount = map(int, input().split())

def dictReverse(dict):
    result = [0, 2, 1, 4, 3]
    return result[dict]

class Shark:
    def __init__(self, x, y, s, d, z):
        self.x = x
        self.y = y
        self.__dict = d
        self.__size = z

        #speed가 왕복하는 거리보다 크면 나머지값만 계산한다
        if self.__dict == 1 or self.__dict == 2:
            self.__speed = s % ((boardSizeX - 1) * 2)
        else:
            self.__speed = s % ((boardSizeY - 1) * 2)

    def move(self):
        moveCount = self.speed

        #방향에 따라 0 또는 (size - 1)까지의 거리보다 높으면 해당 거리로 이동 후 다시 계산
        while moveCount:
            if self.__dict == 1: #위
                if self.x < moveCount:
                    moveCount -= self.x
                    self.x = 0
                    self.__dict = dictReverse(self.__dict)
                else:
                    self.x -= moveCount
                    moveCount = 0
            elif self.__dict == 2: #아래
                if self.x + moveCount >= boardSizeX:
                    moveCount -= (boardSizeX - 1) - self.x
                    self.x = boardSizeX - 1
                    self.__dict = dictReverse(self.__dict)
                else:
                    self.x += moveCount
                    moveCount = 0
            elif self.__dict == 3: #오른쪽
                if self.y + moveCount >= boardSizeY:
                    moveCount -= (boardSizeY - 1) - self.y
                    self.y = boardSizeY - 1
                    self.__dict = dictReverse(self.__dict)
                else:
                    self.y += moveCount
                    moveCount = 0        
            if self.__dict == 4: #왼쪽
                if self.y < moveCount:
                    moveCount -= self.y
                    self.y = 0
                    self.__dict = dictReverse(self.__dict)
                else:
                    self.y -= moveCount
                    moveCount = 0

    def getSize(self):
        return self.__size


if sharkTotalCount == 0:
    print(0)
else:
    #입력
    sharkData = []
    board = [[None] * boardSizeY for _ in range(boardSizeX)]

    for _ in range(sharkTotalCount):
        x, y, speed, dict, size = map(int, input().split())
        x -= 1
        y -= 1
        sharkData.append(Shark(x, y, speed, dict, size))
        board[x][y] = sharkData[-1]

    fishingKingPos = 0
    answer = 0

    while fishingKingPos < boardSizeY:
        #1. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
        for x in range(boardSizeX):
            if board[x][fishingKingPos] != None:
                answer += board[x][fishingKingPos].getSize()
                #상어 리스트에서 제거
                sharkData.remove(board[x][fishingKingPos])
                board[x][fishingKingPos] = None           
                break
        #2. 상어가 이동한다.
        tempBoard = [[None] * boardSizeY for _ in range(boardSizeX)]
        deadShark = []
        for shark in sharkData:
            board[shark.x][shark.y] = None
            shark.move()
            
            #상어 중복 확인
            if tempBoard[shark.x][shark.y] != None:
                if shark.getSize() > tempBoard[shark.x][shark.y].getSize():
                    deadShark.append(tempBoard[shark.x][shark.y])
                    tempBoard[shark.x][shark.y] = shark
                else:
                    deadShark.append(shark)
            else:
                tempBoard[shark.x][shark.y] = shark

        board = tempBoard

        #죽은 상어 제거
        for shark in deadShark:
            sharkData.remove(shark)

        #3. 낚시왕이 오른쪽으로 한 칸 이동한다.
        fishingKingPos += 1

    print(answer)