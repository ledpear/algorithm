// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p, bool bLoop = false) {
		int s_size = s.size();
		int p_size = p.size();

		int s_pos = s_size - 1;
		int p_pos = p_size - 1;

		bool bResult;

		if (p_size == 0)
			return s_size == 0;

		if (s_size == 0)
		{
			int count = 0;
			for (int i = 0; i < p_size; i++)
			{
				if (p[i] == '*')
					count++;
			}
			return count * 2 == p_size;
		}

		if (bResult = (s_size != 0 && (p[p_pos] == s[s_pos] || p[p_pos] == '.')))
		{
			if (bLoop)
			{
				return (isMatch(s, p.substr(0, p_pos - 1)) || (bResult && isMatch(s.substr(0, s_pos), p, true)));
			}
			else
			{ 
				return bResult && isMatch(s.substr(0, s_pos), p.substr(0, p_pos));
			}
		}
		else if (p_size >= 2 && p[p_pos] == '*')
		{
			return (((p[p_pos - 1] == s[s_pos] || p[p_pos-1] == '.') && isMatch(s.substr(0, s_pos), p, true))
				|| isMatch(s, p.substr(0, p_pos - 1)));
		}
		else
		{
			return bResult && isMatch(s.substr(0, s_pos), p.substr(0, p_pos));//false
		}
	}
};

int main()
{
	string s = "aab";
	string p = "b.*";

	Solution sol;
	bool bResult = sol.isMatch(s, p);


    return 0;
}

