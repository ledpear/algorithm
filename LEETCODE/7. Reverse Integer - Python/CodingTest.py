class Solution:
    def reverse(self, x: int) -> int:
        import math
        digit = 0
        Negative = False

        if x < 0:
            x = -x
            Negative = True

        num = str(x)

        if Negative:
            num = num[0:]

        answer = ""
        for i in num:
            answer = i + answer

        if Negative:
            answer = '-' + answer

        answer = int(answer)

        if answer >= 2**31-1 or answer <= -2**31 : return 0
        else :  return answer



print(Solution.reverse(None, 123))
print(Solution.reverse(None, -123))
print(Solution.reverse(None, 120))
print(Solution.reverse(None, 0))
print(Solution.reverse(None, 1534236469))