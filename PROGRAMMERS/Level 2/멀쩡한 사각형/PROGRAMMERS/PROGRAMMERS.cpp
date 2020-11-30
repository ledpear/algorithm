// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

void NumSort(long long &a, long long &b)
{
	if (a < b)
	{
		long long nTemp = a;
		a = b;
		b = nTemp;
	}
}

int main()
{
	int w, h;
	long long answer = 1;
	w = 8;
	h = 12;

	long long nMaxCross;
	long long nCross = w;
	long long tempX = w;
	long long tempY = h;
	long long nW = w;
	long long nH = h;
	NumSort(tempX, tempY);

	if (w == h)
	{
		nMaxCross = w;
	}
	else
	{
		while (true)
		{
			if ((nCross = tempX % tempY) == 0)
			{
				nMaxCross = tempY;
				break;
			}
			else
			{
				tempX = tempY;
				tempY = nCross;
				nMaxCross = nCross;
			}
		}
	}

	return (nW * nH) - (nW + nH - nMaxCross);
}

