from itertools import combinations

while True:
    input_list = list(map(int, input().split()))

    if input_list[0] == 0:
        break

    size = input_list[0]
    arr = input_list[1:]

    result_list = list(combinations(arr, 6))

    for result in result_list:
        for num in result:
            print(num, end = ' ')
        print()

