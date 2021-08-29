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
            self.speed = s % ((boardSizeX - 1) * 2)
        else:
            self.speed = s % ((boardSizeY - 1) * 2)

    def __lt__(self, other):
        if self.__size > other.__size:
            return True
        else :
            return False

    def move(self):
        moveCount = self.speed
        while moveCount:
            posX = self.x + moveX[self.__dict]
            posY = self.y + moveY[self.__dict]

            if 0 <= posX < boardSizeX and 0 <= posY < boardSizeY:
                moveCount -= 1
                self.x = posX
                self.y = posY
            else:
                self.__dict = dictReverse(self.__dict)

    def getSize(self):
        return self.__size


if sharkTotalCount == 0:
    print(0)
else:
    #입력
    sharkData = []
    board = [[[] for _ in range(boardSizeY)] for _ in range(boardSizeX)]
    for _ in range(sharkTotalCount):
        x, y, speed, dict, size = map(int, input().split())
        x -= 1
        y -= 1
        sharkData.append(Shark(x, y, speed, dict, size))
        board[x][y].append(sharkData[-1])

    fishingKingPos = 0
    answer = 0
    eatPos = []

    while fishingKingPos < boardSizeY:
        #1. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
        for x in range(boardSizeX):
            if len(board[x][fishingKingPos]):
                answer += board[x][fishingKingPos][0].getSize()
                #상어 리스트에서 제거
                sharkData.remove(board[x][fishingKingPos][0])
                board[x][fishingKingPos].clear()            
                break
        #2. 상어가 이동한다.
        moveCount = [[0] * boardSizeY for _ in range(boardSizeX)]
        for shark in sharkData:
            board[shark.x][shark.y].remove(shark)
            shark.move()
            moveCount[shark.x][shark.y] += 1
            #큰 크기순으로 저장하기 위해 heapq를 이용하여 추가
            heapq.heappush(board[shark.x][shark.y], shark)

            #리스트의 크기가 2가 되면 먹는 행위가 발생하기 때문에 리스트에 추가
            #2와 일치해야만 추가하는 이유는 상어가 더 추가가 됐을때 중복해서 위치를 추가하지 않기 위해
            if moveCount[shark.x][shark.y] == 2:
                eatPos.append([shark.x, shark.y])

        #2-1 먹는 행위 발생
        for x, y in eatPos:
            if len(board[x][y]) < 2:
                continue
            liveShark = board[x][y][0]
            #죽은 상어는 리스트에서 제거
            for idx in range(1, len(board[x][y])):
                sharkData.remove(board[x][y][idx])
            #리스트를 초기화하고 살아남은 상어를 추가한다
            board[x][y].clear()
            board[x][y].append(liveShark)
        #초기화
        eatPos.clear()

        #3. 낚시왕이 오른쪽으로 한 칸 이동한다.
        fishingKingPos += 1

    print(answer)