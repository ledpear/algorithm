// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int nLast = -1;
	long long n = 118372;
	long long answer = 0;

	vector<int> vTemp;
	while (true)
	{
		vTemp.push_back(n % 10);
		n = n / 10;

		if (n == 0) break;
	}

	sort(vTemp.begin(), vTemp.end());

	while (true)
	{
		answer *= 10;
		answer += vTemp.back();
		vTemp.pop_back();
		if (vTemp.size() == 0) break;
	}

    return 0;
}

