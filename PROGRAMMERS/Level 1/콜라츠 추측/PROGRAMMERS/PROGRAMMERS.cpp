// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int num = 16;
	long long Number = num;
	int nCount = 0;
	while (Number != 1)
	{
		if (Number % 2 == 0)
			Number = Number / 2;
		else
		{
			Number = (Number * 3) + 1;
		}
		nCount++;

		if (nCount >= 500)
		{
			nCount = -1;
			break;
		}
	}
	return nCount;
}

