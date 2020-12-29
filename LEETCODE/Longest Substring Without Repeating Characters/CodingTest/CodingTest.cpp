// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	s = "dvdf";

	vector<char> Words;
	int nMax = 0;

	for (int i = 0; i < s.size(); i++)
	{
		vector<char>::iterator iter = find(Words.begin(), Words.end(), s[i]);

		if (iter != Words.end())
		{
			if (nMax < Words.size())	nMax = Words.size();
			Words.erase(Words.begin(), ++iter);
			Words.push_back(s[i]);
		}
		else
		{
			Words.push_back(s[i]);
		}
	}
	if (nMax < Words.size())	nMax = Words.size();

	return nMax;
}

