def solution(s):
    answer = True
    stack = []
    
    for c in s:
        if c == '(':
            stack.append(c)
        if c == ')':
            if len(stack) > 0:
                stack.pop()
            else:
                answer = False
                break

    if len(stack) != 0:
        answer = False

    return answer