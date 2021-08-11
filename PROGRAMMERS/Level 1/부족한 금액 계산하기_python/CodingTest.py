def solution(price, money, count):
    answer = 0
    
    totalPrice = 0
    for i in range(1, count + 1):
        totalPrice += price * i
        
    if totalPrice > money:
        answer = totalPrice - money

    return answer