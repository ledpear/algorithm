import string
import sys

VOWEL = ['A', 'E', 'I', 'O', 'U']

result = False
count = 0

def BT(targetWord, nowWord, lastIdx = 0):
    global result, count

    if targetWord == nowWord:
        result = True
        return

    if len(nowWord) >= 5:
        return

    for idx in range(len(VOWEL)):
        if not result:
            count += 1
            BT(targetWord, nowWord + VOWEL[idx], lastIdx + 1)
        else:
            break


def solution(word):
    global count
    BT(word, '')
    answer = count
    return answer

print(solution("AAAE"))