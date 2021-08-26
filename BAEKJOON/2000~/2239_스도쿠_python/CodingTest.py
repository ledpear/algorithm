import string
import sys
from typing import Iterator

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

SUDOKU_SIZE = 9
NUMBER_SIZE = 10

#n, m = map(int, input().split())
#k = input().rstrip()

#입력받은 문자열을 배열로 나누고 다시 합친다
#0의 개수를 세고 BT로 개수가 일치하면 최종값이랑 비교해서 더 낮은 값을 저장

sudokuArr = []
blankCount = 0
rowNumber = [[False] * NUMBER_SIZE for _ in range(SUDOKU_SIZE)]
colNumber = [[False] * NUMBER_SIZE for _ in range(SUDOKU_SIZE)]
blockNumber = [[False] * NUMBER_SIZE for _ in range(SUDOKU_SIZE)]
blankPos = []

def getString():
    result = ""
    for idx in range(SUDOKU_SIZE):
        result += ''.join(sudokuArr[idx])
    return result

def getBlockIndex(x, y):
    return (3 * (x // 3)) + (y // 3)

#input
for idx in range(SUDOKU_SIZE):
    sudokuArr.append(input().rstrip())
    sudokuArr[idx] = list(sudokuArr[idx])
    for numIdx, number in enumerate(sudokuArr[idx]):
        if number == '0':
            blankCount += 1
            blankPos.append([idx, numIdx])

#가로줄 숫자
for x in range(SUDOKU_SIZE):
    for y in range(SUDOKU_SIZE):
        nowNum = ord(sudokuArr[x][y]) - ord('0')

        if nowNum != 0:
            rowNumber[x][nowNum] = True
            colNumber[y][nowNum] = True
            blockIndex = getBlockIndex(x, y)
            blockNumber[blockIndex][nowNum] = True

answer = ""

def BT(count):
    global answer
    if count == blankCount:
        answer = getString()
        return

    if answer != "":
        return

    x, y = blankPos[count]
    for number in range(1, NUMBER_SIZE):
        if answer != "":
            return
        if not rowNumber[x][number] and not colNumber[y][number] and not blockNumber[getBlockIndex(x, y)][number]:
            rowNumber[x][number] = True
            colNumber[y][number] = True
            blockNumber[getBlockIndex(x, y)][number] = True
            sudokuArr[x][y] = str(number)
            BT(count + 1)
            rowNumber[x][number] = False
            colNumber[y][number] = False
            blockNumber[getBlockIndex(x, y)][number] = False
            sudokuArr[x][y] = '0'

BT(0)
for idx in range(SUDOKU_SIZE):
    print(answer[idx * 9:idx * 9 + 9])