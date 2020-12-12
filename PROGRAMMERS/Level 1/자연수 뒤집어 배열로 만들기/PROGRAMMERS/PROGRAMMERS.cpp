// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;
	long long n = 12345;

	vector<int> answer;

	while (n != 0)
	{
		answer.push_back(n % 10);
		n = n / 10;
	}

    return 0;
}

