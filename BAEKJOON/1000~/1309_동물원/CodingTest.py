N = int(input())

arr = [[0] * 3 for _ in range(N + 1)]

arr[1][0] = 1
arr[1][1] = 1
arr[1][2] = 1

for i in range(2, N + 1):
    arr[i][0] = (arr[i - 1][0] + arr[i - 1][1] + arr[i - 1][2]) % 9901
    arr[i][1] = (arr[i - 1][0] + arr[i - 1][2]) % 9901
    arr[i][2] = (arr[i - 1][0] + arr[i - 1][1]) % 9901

print(arr[N][0] + arr[N][1] + arr[N][2])