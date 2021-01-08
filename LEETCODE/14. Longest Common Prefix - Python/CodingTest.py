class Solution:
    def longestCommonPrefix(self, strs) -> str:
        strs.sort(key=lambda x : len(x))
        if len(strs) < 1 : return ""

        tempStr = strs[0]
        ResultStr = ""
        TestStr = ""
        for i in range(0, len(tempStr)) :
            TestStr += tempStr[i]
            bResult = True
            for j in range(1, len(strs)) :
                bResult &= strs[j].find(TestStr) == 0
                if bResult == False : break

            if bResult == True :
                if len(ResultStr) < len(TestStr) : ResultStr = TestStr
                else : break

        return ResultStr



print(Solution.longestCommonPrefix(None, ["flower","flow","flight"]))
print(Solution.longestCommonPrefix(None, ["dog","racecar","car"]))