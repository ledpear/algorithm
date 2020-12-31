// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int PalindromicString(string s, int nLeft, int nRight)
{
	int L = nLeft;
	int R = nRight;

	while (L >= 0 && R < s.size() && s[L] == s[R])
	{
		R++;
		L--;
	}

	return R - L - 1;
}

int main()
{
	string s = "ac";
	
	string MaxResult = "";

	int nMax, nPos;
	nMax = 0;
	nPos = 0;

	for (int i = 0; i < s.size(); i++)
	{
		int nShort = PalindromicString(s, i, i);
		int nLong = PalindromicString(s, i, i + 1);
		int nResult;
		if (nShort < nLong)
			nResult = nLong;
		else
			nResult = nShort;

		if (nMax < nResult)
		{
			nMax = nResult;
			nPos = i;
		}
	}

	MaxResult = s.substr(nPos - ((nMax - 1) / 2), nMax);

    return 0;
}

