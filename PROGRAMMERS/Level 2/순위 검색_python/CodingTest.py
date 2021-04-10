import bisect as bs

def DectionaryAdd(dictionary, info, score):
    if (info in dictionary) == True:
        dictionary[info].append(int(score))
    else :
        list = [int(score)]
        dictionary[info] = list

def solution(info, query):
    answer = []

    dictionary = {}

    #info의 모든 경우의 수 map에 추가
    for info_data in info :
        split_data = info_data.split(' ')
        split_score = split_data[4]
        
        # 0
        split_info = split_data[0] + split_data[1] + split_data[2] + split_data[3]
        DectionaryAdd(dictionary, split_info, split_score)
        # 1
        split_info = '-' + split_data[1] + split_data[2] + split_data[3]
        DectionaryAdd(dictionary, split_info, split_score)
        split_info = split_data[0] + '-' + split_data[2] + split_data[3]
        DectionaryAdd(dictionary, split_info, split_score)
        split_info = split_data[0] + split_data[1] + '-' + split_data[3]
        DectionaryAdd(dictionary, split_info, split_score)
        split_info = split_data[0] + split_data[1] + split_data[2] + '-'
        DectionaryAdd(dictionary, split_info, split_score)
        #2
        split_info = '-' + '-' + split_data[2] + split_data[3]
        DectionaryAdd(dictionary, split_info, split_score)
        split_info = '-' + split_data[1] + '-' + split_data[3]
        DectionaryAdd(dictionary, split_info, split_score)
        split_info = '-' + split_data[1] + split_data[2] + '-'
        DectionaryAdd(dictionary, split_info, split_score)
        split_info = split_data[0] + '-' + '-' + split_data[3]
        DectionaryAdd(dictionary, split_info, split_score)
        split_info = split_data[0] + '-' + split_data[2] + '-'
        DectionaryAdd(dictionary, split_info, split_score)
        split_info = split_data[0] + split_data[1] + '-' + '-'
        DectionaryAdd(dictionary, split_info, split_score)
        #3
        split_info = '-' + '-' + '-' + split_data[3]
        DectionaryAdd(dictionary, split_info, split_score)
        split_info = '-' + '-' + split_data[2] + '-'
        DectionaryAdd(dictionary, split_info, split_score)
        split_info = '-' + split_data[1] + '-' + '-'
        DectionaryAdd(dictionary, split_info, split_score)
        split_info = split_data[0] + '-' + '-' + '-'
        DectionaryAdd(dictionary, split_info, split_score)
        #4
        split_info = '-' + '-' + '-' + '-'
        DectionaryAdd(dictionary, split_info, split_score)

    #딕셔너리 정렬
    for key in dictionary.keys():
        dictionary[key].sort()

    #query 문자열 처리
    for query_data in query:
        split_point = query_data.rfind(' ')
        query_info = query_data[0:split_point]
        query_info = query_info.replace(' and ', '')
        query_score = int(query_data[split_point+1:])

        if query_info in dictionary.keys() :
            score_list = dictionary[query_info]
            answer.append(len(score_list) - bs.bisect_left(score_list, query_score))
        else:
            answer.append(0)
        
    return answer

info = ["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]
query = ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]
print(solution(info, query))