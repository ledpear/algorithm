from string import ascii_lowercase
from string import digits

def solution(new_id):
    #1
    new_id = new_id.lower()
    #2
    check_list = list(ascii_lowercase)
    check_list += list(digits)
    check_list.append('-')
    check_list.append('_')
    check_list.append('.')

    temp_id = ""
    for c in new_id:
        if c in check_list:
            temp_id += c
    new_id = temp_id

    #3
    temp_id = ""
    count = 0
    for c in new_id:
        if c == '.':
            count += 1
            if count < 2:
                temp_id += c
        else:
            temp_id += c
            count = 0
    new_id = temp_id

    #4
    if len(new_id) != 0:
        if new_id[0] == '.':
            new_id = new_id[1:]
    if len(new_id) != 0:
        if new_id[-1] == '.':
            new_id = new_id[:-1]
    #5
    else:
        new_id += 'a'
    
    #6
    if len(new_id) >= 16:
        new_id = new_id[:15]
    if new_id[-1] == '.':
        new_id = new_id[:-1]

    #7
    while len(new_id) <= 2:
        new_id += new_id[-1]

    return new_id

#print(solution("...!@BaT#*..y.abcdefghijklm"))
#print(solution("z-+.^."))
print(solution("=.="))
#print(solution("123_.def"))
#print(solution(	"abcdefghijklmn.p"))