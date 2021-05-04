def solution(s):
    answer = 0
    stack = []

    for c in s:
        if len(stack) == 0:
            stack.append(c)
        elif stack[-1] == c:
            stack = stack[:-1]
        else:
            stack.append(c)

    if len(stack) == 0:
        return 1
    else:
        return 0

solution("baabaa")