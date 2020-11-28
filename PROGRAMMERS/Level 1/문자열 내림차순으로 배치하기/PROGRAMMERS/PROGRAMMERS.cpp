// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return b < a;
}

int main()
{
	int nLast = -1;

	string s = "Zbcdefg";
	string answer = "";

	vector <char> Str;

	sort(s.begin(), s.end(), compare);
// 
// 	for (int i = 0; i < s.size(); i++)
// 	{
// 		Str.push_back(s[i]);
// 	}
// 
// 	sort(Str.begin(), Str.end());
// 
// 	for (int i = 0; i < s.size(); i++)
// 	{
// 		answer += Str[i];
// 	}

    return 0;
}

