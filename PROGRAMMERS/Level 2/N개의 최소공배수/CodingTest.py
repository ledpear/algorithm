from math import gcd

def lcm(x, y):
    return x * y // gcd(x, y)

def solution(arr):
    answer = 0
    return answer