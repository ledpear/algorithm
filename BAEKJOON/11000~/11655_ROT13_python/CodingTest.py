from string import ascii_uppercase
from string import ascii_lowercase

def ROT13(c):
    list_upper = list(ascii_uppercase)
    list_lower = list(ascii_lowercase)

    if c in list_upper :
        i = list_upper.index(c) + 13
        if i >= 26:
            i -= 26
        return list_upper[i]

    if c in list_lower :
        i = list_lower.index(c) + 13
        if i >= 26:
            i -= 26
        return list_lower[i]

    return c

input = list(input())

size = len(input)

for i in range(size):
    input[i] = ROT13(input[i])

print(''.join(input))