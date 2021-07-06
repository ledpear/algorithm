import string
import sys
from collections import deque

input = sys.stdin.readline

#1부터 100까지 visit배열을 만들어서 BFS 탐색을 한다 
#이동한 칸에 사다리나 뱀이 있다면 이동 위치로 판단한다.
#visit 판단은 이동한곳과 사다리나 뱀을 탄 곳 둘다 체크

ladder_size, snake_size = map(int, input().split())

#해당칸에 도착했을 때 move의 값이 0이 아니라면 사다리나 뱀이 있는것
ladder_move = [0] * 100
snake_move = [0] * 100

#사다리 입력
for _ in range(ladder_size):
    start, end = map(int, input().split())
    ladder_move[start] = end
#뱀 입력
for _ in range(snake_size):
    start, end = map(int, input().split())
    snake_move[start] = end

#BFS
def BFS(ladder_move, snake_move):
    queue = deque()
    queue.append([1, 0]) #시작위치, 주사위 횟수
    visit = [False] * 101

    while queue:
        now_pos, now_score = queue.popleft()

        for i in range(1, 7):
            move_pos = now_pos + i

            if move_pos == 100:
                return (now_score + 1)
            elif not visit[move_pos]:
                visit[move_pos] = True
                
                if ladder_move[move_pos] != 0:
                    move_pos = ladder_move[move_pos]
                    if not visit[move_pos]:
                        visit[move_pos] = True
                        queue.append([move_pos, now_score + 1])
                elif snake_move[move_pos] != 0:
                    move_pos = snake_move[move_pos]
                    if not visit[move_pos]:
                        visit[move_pos] = True
                        queue.append([move_pos, now_score + 1])
                else:
                    queue.append([move_pos, now_score + 1])

print(BFS(ladder_move, snake_move))