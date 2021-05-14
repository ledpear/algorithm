import string

def isAlphabet(w):
    if w in string.ascii_lowercase or w in string.ascii_uppercase:
        return True
    else:
        return False

def makeList(word):
    temp = ''
    arr = []
    size = len(word)
    w1 = word[0]
    w2 = ''
    w1_alphabet = isAlphabet(w1)
    w2_alphabet = False

    for i in range(1, size):
        w2 = word[i]
        w2_alphabet = isAlphabet(w2)
        if w1_alphabet and w2_alphabet:
            arr.append((w1+w2).lower())
        w1 = w2
        w1_alphabet = w2_alphabet
            
    return arr

def makeSet(str1_arr, str2_arr):
    intersection = []
    union = []

def solution(str1, str2):
    answer = 0

    str1_arr = makeList(str1)
    str2_arr = makeList(str2)

    str1_index = 0
    str2_index = 0

    str1_arr.sort()
    str2_arr.sort()

    str1_size = len(str1_arr)
    str2_size = len(str2_arr)

    if str1_size == 0 and str2_size == 0:
        return 65536

    intersection = 0
    union = 0

    while str1_index < str1_size or str2_index < str2_size:
        if str1_index == str1_size:
            union += 1
            str2_index += 1
            continue

        if str2_index == str2_size:
            union += 1
            str1_index += 1
            continue

        if str1_arr[str1_index] == str2_arr[str2_index]:
            intersection += 1
            union += 1
            str1_index += 1
            str2_index += 1
        else:
            if str1_arr[str1_index] < str2_arr[str2_index]:
                union += 1
                str1_index += 1
            else:
                union += 1
                str2_index += 1

    if union == 0:
        return 0

    result = intersection / union
    answer = int(result * 65536)
    return answer


str1 = 'E=M*C^2'
str2 = 'e=m*c^2'

print(solution(str1, str2))