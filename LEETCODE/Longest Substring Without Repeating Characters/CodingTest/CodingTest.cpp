// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	string s;
	s = "pwwkew";
	int nMax = 0;

	string temp = "";

	for (int i = 0; i < s.size(); i++)
	{
		if (temp.size() == 0)
		{
			temp += s[i];
			continue;
		}		

		if (temp[0] != s[i])
		{
			temp += s[i];
		}
		else
		{
			while (true)
			{
				if (i + temp.size() > s.size())
				{
					if (nMax <= temp.size())
						nMax = temp.size();
					temp = s[i];
					break;
				}
				else if (temp.compare(s.substr(i, temp.size())) == 0)
				{
					i += temp.size();
				}
				else
				{
					if (nMax <= temp.size())
						nMax = temp.size();
					temp = s[i];
					break;
				}
			}			
		}
	}


    return 0;
}

