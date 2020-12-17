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
	vector<int> d = { 1,3,2,5,4 };
	int budget = 9;
	int answer = 0;

	sort(d.begin(), d.end());
	int nTotal = 0;
	int i;
	for (i = 0; i < d.size(); i++)
	{
		nTotal += d[i];
		if (nTotal > budget)
		{
			break;
		}
	}

	answer = i;

    return 0;
}

