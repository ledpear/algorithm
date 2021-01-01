// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x = 1534236469;

	long long num = x;
	bool Negative = false;
	if (num < 0)
	{
		num *= -1;
		Negative = true;
	}

	long long temp = num;
	int digit = 0;
	while (temp > 0)
	{
		temp = temp / 10;
		digit++;
	}
	long long nResult = 0;
	digit--;
	for (int i = 0; digit >= 0; i++)
	{
		nResult += pow(10, digit--) * (num % 10);
		num = num / 10;
	}
	if (Negative)
		nResult *= -1;
    return 0;
}

