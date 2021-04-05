

def solution(land):
    answer = 0

    size = len(land)

    DP = [[0] * 4 for _ in range(size)]

    for index in range(0, size) :
        if(index == 0):
            for i in range(0, 4):
                DP[index][i] = land[index][i]
        else:
            for i in range(0,4):
                floorMax = 0
                
                for j in range(0, 4):
                    if(i == j):
                        continue

                    floorMax = max(floorMax, DP[index -1][j])
                
                DP[index][i] = land[index][i] + floorMax

    for i in range(0, 4):
        answer = max(answer, DP[size - 1][i])


    return answer

print(solution([[1,2,3,5],[5,6,7,8],[4,3,2,1]]))