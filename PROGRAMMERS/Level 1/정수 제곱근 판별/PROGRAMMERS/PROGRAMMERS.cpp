// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int nLast = -1;

	long long n = 3;
	long long answer = 0;

	long double temp;
	temp = sqrt(n);

	if (temp - (long long)temp > 0)
		return -1;
	else
		return pow(++temp, 2);

    return 0;
}

