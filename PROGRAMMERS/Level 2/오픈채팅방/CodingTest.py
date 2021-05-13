def solution(record):
    answer = []
    db = {}
    chatting = []

    for log in record:
        log_list = log.split()

        if log_list[0] == 'Enter':
            db[log_list[1]] = log_list[2]
            chatting.append([True, log_list[1]])
        elif log_list[0] == 'Leave':
            chatting.append([False, log_list[1]])
        elif log_list[0] == 'Change':
            db[log_list[1]] = log_list[2]

    for chat in chatting:
        if chat[0]:
            answer.append(db[chat[1]] + '님이 들어왔습니다.')
        else:
            answer.append(db[chat[1]] + '님이 나갔습니다.')
    
    return answer


print(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]))