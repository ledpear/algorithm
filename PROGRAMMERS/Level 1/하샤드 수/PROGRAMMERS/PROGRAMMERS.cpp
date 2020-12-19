// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;
	int x = 11;

	int Ori = x;
	bool answer = true;
	int sum = 0;

	while (x != 0)
	{
		sum += x % 10;
		x /= 10;
	}

	answer = (Ori % sum == 0);

    return 0;
}

