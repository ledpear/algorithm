class Solution:
    def CompareWord(str1, str2) -> str:

        if len(str1) < len(str2) :
            compare1 = str1
            compare2 = str2
        else:
            compare1 = str2
            compare2 = str1

        strTest = ""
        for i in range(len(compare1)) :
            if compare1[i] == compare2[i] :
                strTest += compare1[i]
            else:
                break

        return strTest

    def DivisionList(strs) -> str:
        size = len(strs)
        halfSize = size//2
        strResult = ""
        if size > 2 :
            strs1 = list(strs[:halfSize])
            strs2 = list(strs[halfSize:])

            strResult = Solution.CompareWord(Solution.DivisionList(strs1), Solution.DivisionList(strs2))

            return strResult
        elif size == 2 :
            strResult = Solution.CompareWord(strs[0],strs[1])

            return strResult
        elif size == 1 :
            return strs[0]
        else:
            return ""

    def longestCommonPrefix(self, strs) -> str:

        return Solution.DivisionList(strs)



print(Solution.longestCommonPrefix(None, ["flower","flow","flight"]))
print(Solution.longestCommonPrefix(None, ["dog","racecar","car"]))