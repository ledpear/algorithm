class Solution:
    def romanToInt(self, s: str) -> int:
        nResult = 0
        while(True) :
            tempStr = s[0]
            if tempStr == "M" :
                nResult += 1000
            elif tempStr == "D" :
                nResult += 500
            elif tempStr == "C" :
                if len(s) > 1 and s[1] == "D" :
                    nResult += 400
                    s = s[1:]
                elif len(s) > 1 and s[1] == "M" :
                    nResult += 900
                    s = s[1:]
                else:
                    nResult += 100
            elif tempStr == "L" :
                nResult += 50
            elif tempStr == "X" :
                if len(s) > 1 and s[1] == "L" :
                    nResult += 40
                    s = s[1:]
                elif len(s) > 1 and s[1] == "C" :
                    nResult += 90
                    s = s[1:]
                else:
                    nResult += 10
            elif tempStr == "V" :
                nResult += 5
            elif tempStr == "I" :
                if len(s) > 1 and s[1] == "V" :
                    nResult += 4
                    s = s[1:]
                elif len(s) > 1 and s[1] == "X" :
                    nResult += 9
                    s = s[1:]
                else:
                    nResult += 1

            if len(s) <= 1 : break
            else : s = s[1:]

        return nResult

print(Solution.romanToInt(None, "III"))
print(Solution.romanToInt(None, "IV"))
print(Solution.romanToInt(None, "IX"))
print(Solution.romanToInt(None, "LVIII"))
