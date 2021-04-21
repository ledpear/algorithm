from itertools import combinations

def solution(orders, course):
    answer = []

    for course_size in course:
        dict = {}

        for order in orders:
            
            for combi in combinations(order, course_size):
                val = ''.join(sorted(combi))
                if val in dict:
                    dict[val] += 1
                else:
                    dict[val] = 1       

        if len(dict) == 0 : continue

        list = sorted(dict.items(), reverse=True, key=lambda item:item[1])

        max = list[0][1]
        
        if max >= 2 :
            for i in list:
                if max != i[1]:
                    break
                answer.append(i[0])

    answer.sort()
    
    return answer


orders = ["XYZ", "XWY", "WXA"]
course = [2,3,4]

print(solution(orders, course))
#print(dict)




