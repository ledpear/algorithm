import string
import sys
import heapq

input = sys.stdin.readline

n = int(input().rstrip())
#n, m = map(int, input().split())

#각 자리마다 최대갯수 글자 확인
#각 자리마다 해당 글자의 갯수 확인
#각 자리마다 최대갯수를 저장할 배열이 있어야함
#각 자리마다 알파뱃 배열이 있어야함

#예외처리 리스트
#1. 최다 알파벳이 여러개 일 경우
#2. 최다 알파벳이 결정되어있을 경우

def AlphabetToIndex(c):
    return ord(c) - 65

arr = []
max_len = 0

#알파벳 입력
#알파벳이 최대 8자까지만 있으므로 8길이인 배열로 저장

#각 자리별 알파뱃 배열
alphabet_arr = [[0] * 26 for _ in range(8)]

#각 자리별 최대 알파뱃 [갯수, 인덱스값]
Maximum_arr = [[0, -1] for _ in range(8)]

#각 자리별 알파뱃 리스트
alphabet_list = [[] for _ in range(8)]

for i in range(n):
    input_temp = input().rstrip()
    arr.append(input_temp)

    #입력된 알파벳의 최대 길이 저장
    size = len(arr[i])
    if size > max_len:
        max_len = size

    i = 0
    for c in input_temp[::-1]:
        #자릿수별 알파벳 저장
        alphabet_list[i].append(c)

        #자릿수별 알파벳 증가
        alphabet_index = AlphabetToIndex(c)
        alphabet_arr[i][alphabet_index] += 1

        #자릿수별 최대 알파벳 확인 동일한 경우 추가
        if alphabet_arr[i][alphabet_index] > Maximum_arr[i][0]:
            Maximum_arr[i].clear
            Maximum_arr[i].append([alphabet_arr[i][alphabet_index], alphabet_index])
        elif alphabet_arr[i][alphabet_index] == Maximum_arr[i][0]:
            Maximum_arr[i].append([alphabet_arr[i][alphabet_index], alphabet_index])

        i += 1

#각 자리별 힙 생성 [갯수, 인덱스값]
alphabet_heap = [[] for _ in range(8)]

for i in range(size):
    alphabet_visit = [False] * 26

    for c in alphabet_list[i]:
        alphabet_index = AlphabetToIndex(c)
        if not alphabet_visit[alphabet_index]:
            alphabet_visit[alphabet_index] = True
            heapq.heappush(alphabet_heap[i], [-alphabet_arr[i][alphabet_index], alphabet_index])

#최대 자릿수 부터 아래로 내려가면서 알파벳 값 계산
alphabet_value = [0] * 26
alphabet_used = [False] * 26

value = 9

for i in range(size):
    pos = size - i - 1

    #이미 처리한 문자 통과
    while alphabet_heap[pos]:
        if alphabet_used[alphabet_heap[pos][0][1]]:
            heapq.heappop(alphabet_heap[pos])
        else:
            break

    #모든 문자를 처리했을경우 컨티뉴
    if len(alphabet_heap[pos]) == 0:
        continue

    temp_arr = []
    temp_arr.append(heapq.heappop(alphabet_heap[pos]))

    while alphabet_heap[pos]:
        if temp_arr[0][0] == alphabet_heap[pos][0][0]:
            temp_arr.append(heapq.heappop(alphabet_heap[pos]))
        else:
            break

    if len(temp_arr) == 1:
        alphabet_used[temp_arr[0][1]] = True
        alphabet_value[temp_arr[0][1]] = value
    elif len(temp_arr) > 1:
        temp_pos = pos - 1
        while temp_pos >= 0:
            new_arr = [[0, -1]]

            #다음 자리 수 에서 가장 큰 값 탐색
            for iter in temp_arr:
                if alphabet_arr[temp_pos][iter[1]] > -new_arr[0][0]:
                    new_arr.clear()
                    new_arr.append(iter)
                elif iter[0] == new_arr[0][0]:
                    new_arr.append(iter)

            #가장 큰 값이 한개이면 바로 끝나고 아니면 다시 탐색
            if len(new_arr) == 1:
                alphabet_used[temp_arr[0][1]] = True
                alphabet_value[temp_arr[0][1]] = value
                break
            elif new_arr[0][1] != -1:
                temp_arr = new_arr
            temp_pos -= 1

    #마지막까지 동일하다면 순서대로 값 주입
    if len(temp_arr) > 1:
        for iter in temp_arr:
            alphabet_used[iter[1]] = True
            alphabet_value[iter[1]] = value
            value -= 1
    else:
        value -= 1

answer = 0
upper = 1
for i in range(size):
    for n in alphabet_list[i]:
        answer += alphabet_value[AlphabetToIndex(n)] * upper

    upper *= 10

print(answer)