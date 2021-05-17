input = input()

size = len(input)
result = 1

size_half = int(size / 2)
for i in range(0, size_half):
    if input[i] != input[size - i - 1]:
        result = 0
        break

print(result)