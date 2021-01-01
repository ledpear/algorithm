class Solution:
    def reverse(text):
        result = ""
        for i in text :
            result = i + result

        return result

    def isPalindrome(self, x: int) -> bool:
        Num = str(x)
        ReverseNum = Solution.reverse(Num)

        return Num == ReverseNum

print(Solution.isPalindrome(None, 121))
print(Solution.isPalindrome(None, -121))
print(Solution.isPalindrome(None, 10))
print(Solution.isPalindrome(None, -101))
print(Solution.isPalindrome(None, 1221))