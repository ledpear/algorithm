// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;
	int n = 12;
	int answer = 1;

	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
			answer += i;
	}
	answer += n;

	if (n == 0)
		answer = 0;
	else if (n == 1)
		answer = 1;

    return 0;
}

