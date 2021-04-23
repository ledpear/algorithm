size = int(input())
size_list = list(map(int, input().split()))
dp = [1] * size

for i in range(1, size):
    index = i - 1
    while index >= 0:
        if size_list[index] < size_list[i]:
            dp[i] = max(dp[i], dp[index] + 1)
        index -= 1
        
print(max(dp))