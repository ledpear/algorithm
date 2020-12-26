// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int answer = 0;
	int nCount = 1;
	unsigned long Num0 = 0;
	unsigned long Num1 = 1;
	unsigned long temp = 0;

	if (n == 1)
		return 1;

	unsigned long a = 1234567;

	while (true)
	{
		temp = Num1 % a;
		Num1 += Num0;
		Num1 = Num1 % a;
		Num0 = temp;
		if (++nCount == n)
			break;
	}

	Num1 = Num1 % a;
	return Num1;
}

