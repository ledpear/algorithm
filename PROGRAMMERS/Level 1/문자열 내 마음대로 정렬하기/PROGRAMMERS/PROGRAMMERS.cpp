// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int set;

bool compare(string a, string b)
{
	if(a[set] != b[set])
		return a[set] < b[set];
	else
	{
		return a < b;
	}
}

int main()
{
	vector<string> strings;

	set = 2;
	strings.push_back("abce");
	strings.push_back("abcd");
	strings.push_back("cdx");

	sort(strings.begin(), strings.end(), compare);

	vector<string> answer;

    return 0;
}

