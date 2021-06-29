def getResult(time, times):
    answer = 0
    for t in times:
        answer += time // t
    return answer

def solution(n, times):
    answer = 0
    
    start = 0
    end = int(1e20)
    
    while start <= end:
        time = (start + end) // 2
        result = getResult(time, times)
        
        if result < n:
            start = time + 1
        else:
            answer = time
            end = time - 1
    
    return answer