class Solution:
    def getRoman(size:int) -> str:
        if size == 4 :
            return "M"
        elif size == 3 :
            return "C"
        elif size == 2 :
            return "X"
        elif size == 1 :
            return "I"

    def getHelfRoman(size:int) -> str :
        if size == 3 :
            return "D"
        elif size == 2 :
            return "L"
        elif size == 1 :
            return "V"

    def intToRoman(self, num) -> str:
        strNum = str(num)
        strResult = ""

        while strNum :
            size = len(strNum)
            strRoman = Solution.getRoman(size)
            tempNum = int(strNum[0])

            if tempNum < 5 :
                if tempNum == 4 :
                    strResult = strResult + strRoman + Solution.getHelfRoman(size)
                else:
                    for i in range(0, tempNum) :
                        strResult = strResult + strRoman
            else :
                tempNum -= 5
                if tempNum == 4 :
                    strResult = strResult + strRoman + Solution.getRoman(size + 1)
                else:
                    strResult += Solution.getHelfRoman(size)
                    for i in range(0, tempNum) :
                        strResult = strResult + strRoman

            if size == 1 : break
            else : strNum = strNum[1:]

        return strResult

print(Solution.intToRoman(None, 3))
print(Solution.intToRoman(None, 4))
print(Solution.intToRoman(None, 9))
print(Solution.intToRoman(None, 58))
print(Solution.intToRoman(None, 1994))