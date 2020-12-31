// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

string PalindromicString(string s, int nLeft, int nRight)
{
	int L = nLeft;
	int R = nRight;
	string strResult = "";

	while (L >= 0 && R < s.size() && s[L] == s[R])
	{
		if (L != R)
		{
			strResult += s[R];
			strResult = s[L] + strResult;
		}
		else
			strResult += s[L];

		R++;
		L--;
	}

	return strResult;
}

int main()
{
	string s = "ac";
	
	string MaxResult = "";

	string strResult, temp, LongString, ShortString;

	for (int i = 0; i < s.size(); i++)
	{
		string strSmall, strLarge;
		strSmall = PalindromicString(s, i, i);
		if (i + 1 < s.size())
			strLarge = PalindromicString(s, i, i + 1);
		else
			strLarge = "";

		if (strSmall.size() < strLarge.size())
			strResult = strLarge;
		else
			strResult = strSmall;

		if (MaxResult.size() < strResult.size())
			MaxResult = strResult;
	}

    return 0;
}

