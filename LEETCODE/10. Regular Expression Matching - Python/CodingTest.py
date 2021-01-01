class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        p_list = list(p).reverse()
        s_list = list(s).reverse()
        bResult = True
        s_pos = 0
        for i in p_list :
            if i == '.' :
                s_pos += 1
            elif i == '*' :
                p_list[]
            else
                if i != s_list[s_pos] :
                    bResult = False
                    break;





print(Solution.isMatch(None, "aa","a"))