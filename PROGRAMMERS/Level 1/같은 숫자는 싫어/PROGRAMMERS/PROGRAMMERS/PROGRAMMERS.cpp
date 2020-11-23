// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;
	vector<int> answer;
	vector<int> arr;

	for (int i = 0; i < arr.size(); i++)
	{
		if (nLast != arr[i])
		{
			nLast = arr[i];
			answer.push_back(arr[i]);
		}
	}

    return 0;
}

