// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	long long answer = 0;

	int a = 5;
	int b = 3;

	if (a == b)
	{
		return a;
	}
	else if (a < b)
	{
		for (int i = a; i <= b; i++)
			answer += i;
	}
	else
	{
		for (int i = b; i <= a; i++)
			answer += i;
	}

    return answer;
}

