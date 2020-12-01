// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	string s = "a234";
	bool answer = true;

	if (s.size() == 4 || s.size() == 6)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if('0' > s[i] || s[i] > '9')
				return false;
		}
		return true;
	}

	return false;
}

