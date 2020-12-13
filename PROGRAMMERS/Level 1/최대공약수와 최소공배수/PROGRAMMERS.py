answer = ''
n = 2
m = 5

nMax = -1
for i in range(1, min(n,m) + 1):
    if(n % i == 0 and m % i == 0):
        if(nMax < i ):
            nMax = i;

nMin = (n * m) / nMax
answer = [nMax, nMin]