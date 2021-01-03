// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int s_size = s.size();
		int p_size = p.size();

		bool bResult;

		if (p_size == 0)
			return s_size == 0;
		bResult = (s_size != 0 && (p[0] == s[0] || p[0] == '.'));

		if (p_size >= 2 && p[1] == '*')
		{
			return (isMatch(s, p.substr(2)) || (bResult && isMatch(s.substr(1), p)));
		}
		else
		{
			return bResult && isMatch(s.substr(1), p.substr(1));
		}
	}
};

int main()
{
	string s = "aaaaaa";
	string p = "b***";

	Solution sol;
	bool bResult = sol.isMatch(s, p);


    return 0;
}

