import math

def solution(n,a,b):
    count = int(math.log2(n))
    size = n
    low = 1
    high = n

    while True:
        half = int(size / 2) + low
        if (a < half) == (b < half) :
            if a < half:
                high = half - 1
            else:
                low = half
            count -= 1
            size = size // 2
        else:
            break

    return count

solution(8, 4, 3)