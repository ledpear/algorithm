def check(line_list, time):
    count = 0
    start = time
    end = start + 1000
    for line in line_list:
        if start <= line[1] and line[0] < end:
                count += 1
    return count

def solution(lines):
    answer = 1
    line_list = []
    
    for line in lines:
        y, t, s = line.split(' ')
        t = t.split(':')
        s = float(s.replace('s','')) * 1000
        
        end = (float(t[0]) * 3600 + float(t[1]) * 60 + float(t[2])) * 1000
        start = end - s + 1
        line_list.append([start, end])
        
    for line in line_list:
        answer = max(answer, check(line_list, line[0]), check(line_list, line[1]))
        
    return answer