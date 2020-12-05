// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;
	string s = "a B z";
	int n = 4;

	string answer = "";
	int temp;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			answer += ' ';
		else if ('a' <= s[i] && s[i] <= 'z')
		{
			if ('z' < s[i] + n)
			{
				answer += (s[i] + n) - ('z' - 'a' + 1);
			}
			else
				answer += (s[i] + n);
		}
		else if ('A' <= s[i] && s[i] <= 'Z')
		{
			if ('Z' < s[i] + n)
			{
				answer += (s[i] + n) - ('Z' - 'A' + 1);
			}
			else
				answer += (s[i] + n);
		}
	}

    return 0;
}

