class Solution:
    def myAtoi(self, s: str) -> int:
        s.lstrip()
        num = 0
        Nagative = False
        pos = 0
        for i in s :
            if i == ' ' :
                s.lstrip()
                continue
            elif i == '-' and pos == 0 :
                Nagative = True
            elif '0' <= i <= '9':
                num *= 10
                num += int(i)
            else :
                break
            if pos == 0 :
                pos += 1

        if Nagative:
            num *= -1

        if num > 2**31 : num = 2**31
        elif num <= -2**31 : num = -2**31 + 1

        return num

print(Solution.myAtoi(None, "42"))
print(Solution.myAtoi(None, "   -42"))
print(Solution.myAtoi(None, "4193 with words"))
print(Solution.myAtoi(None, "words and 987"))
print(Solution.myAtoi(None, "-91283472332"))