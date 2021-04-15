def combinations(input, dict, item = "", count = 0, start_point = 0):
    if 2 <= count:
        if item in dict:
            dict[item] += 1
        else:
            dict[item] = 1

    for i in range(start_point, len(input)):
        temp = item + input[i]
        combinations(input, dict, temp, count + 1, i + 1)

dict = {}

combinations("ABCDE", dict)

print(dict)



def solution(orders, course):
    answer = []

    dict = {}

    combinations("ABCDE", dict)

    print(dict)

    return answer

