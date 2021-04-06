

def solution(s):
    answer = []
    string = s[1:len(s) - 1]
    list = []

    string_temp = ""
    start = False
    for c in string :
        if c == '{':
            start = True
        elif c == '}':
            string_temp += c
            list.append(string_temp)
            string_temp = ""
            start = False

        if start == True :
            string_temp += c

    sorted_list = sorted(list, key=len)

    for item in sorted_list:
        item_list = item[1:len(item)-1].split(',')

        for s_num in item_list:
            num = int(s_num)
            if num not in answer:
                answer.append(int(num))

    return answer

print(solution("{{1,2,3},{2,1},{1,2,4,3},{2}}"))