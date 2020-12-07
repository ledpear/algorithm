// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int nLast = -1;
	int n = 987;
	int answer = 0;

	string temp;
	temp = to_string(n);
	for (int i = 0; i < temp.size(); i++)
	{
		answer += (temp[i] - '0');
	}

    return 0;
}

