// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;
	string phone_number;
	string answer = "";

	for (int i = 0; i < phone_number.size(); i++)
	{
		if (i < phone_number.size() - 4)
		{
			answer += '*';
		}
		else
		{
			answer += phone_number[i];
		}		
	}

    return 0;
}

