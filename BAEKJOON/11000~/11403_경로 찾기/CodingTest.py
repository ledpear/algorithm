size = int(input())
matrix = []

for i in range(size):
    matrix.append(list(map(int, input().split(' '))))

#일반적인 플로이드 위샬
def floyd_warshall(matrix, size):
    for i in range(size):
        for j in range(size):
            for k in range(size):
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])

#연결확인 플로이드 위샬
def floyd_warshall_custom(matrix, size):
    for k in range(size):
        for i in range(size):
            for j in range(size):
                if matrix[i][k] and matrix[k][j]:
                    matrix[i][j] = 1

floyd_warshall_custom(matrix, size)

for i in range(0, size) :
    _str = ""
    for j in range(0, size) :
        _str += str(matrix[i][j]) +  " "
    print(_str)