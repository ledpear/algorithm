// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;

	vector<int> a;
	vector<int> b;
	int answer = 1234567890;

	answer = 0;
	for (int i = 0; i < a.size(); i++)
	{
		answer = answer + (a[i] * b[i]);
	}

    return 0;
}

