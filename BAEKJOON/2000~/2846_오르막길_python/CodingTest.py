size = int(input())
arr = list(input().split())

result = 0

start = 0
end = 0

for i in range(size - 1):
    if int(arr[i]) < int(arr[i + 1]):
        if start == 0:
            start = int(arr[i])
            end = int(arr[i + 1])
        else:
            end = int(arr[i + 1])
    else:
        if start != 0:
            result = max(result, end - start)
            start = 0
            end = 0

if start != 0:
    result = max(result, end - start)
    start = 0
    end = 0

print(result)