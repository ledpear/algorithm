// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int answer = 0;
	int n = 10;
	
	bool *PrimeNumber = new bool[n+1] {};

	for (int i = 2; i <= n; ++i)
	{
		if(PrimeNumber[i] == true)	continue;
		int pos = 2;
		while (i*pos <= n)
		{
			PrimeNumber[i * pos++] = true;
		}
	}

	for (int i = 2; i <= n; ++i)
	{
		if (PrimeNumber[i] == false)
			answer++;
	}

	delete[] PrimeNumber;

    return answer;
}

