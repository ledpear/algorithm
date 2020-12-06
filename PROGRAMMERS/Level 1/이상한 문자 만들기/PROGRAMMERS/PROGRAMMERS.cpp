// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;
	string s = "try hello world";

	string answer = "";

	int pos = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			pos = 0;
			answer += ' ';
		}
		else if (pos % 2 == 0)
		{
			if ('a' <= s[i] && s[i] <= 'z')
			{
				answer += s[i] + ('A' - 'a');
			}
			else
				answer += s[i];

			pos++;
		}
		else if (pos % 2 == 1)
		{
			if ('A' <= s[i] && s[i] <= 'Z')
			{
				answer += s[i] - ('A' - 'a');
			}
			else
				answer += s[i];

			pos++;
		}
	}

    return 0;
}

