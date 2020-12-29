// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s = "10 -21 35 -44";
	string answer;

	int nLast = -1;
	int nMax;
	int nMin;
	int nPow = 0;

	bool Flag = false;

	string strTemp;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			int nTemp = 0;

			for (int j = strTemp.size() - 1; j >= 0; j--)
			{
				if (strTemp[j] == '-')
				{
					nTemp *= -1;
				}
				else
				{
					nTemp += (pow(10, nPow++) * (strTemp[j] - '0'));
				}
			}

			if (!Flag)
			{
				nMax = nTemp;
				nMin = nTemp;
				Flag = true;
			}
			else
			{
				if (nMax < nTemp)	nMax = nTemp;
				if (nMin > nTemp)	nMin = nTemp;
			}

			nPow = 0;
			strTemp = "";
		}
		else
		{
			strTemp += s[i];
			if (i == (s.size() - 1))
				s += ' ';
		}
	}

	answer += to_string(nMin);
	answer += ' ';
	answer += to_string(nMax);

	return 0;
}

