// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;
	vector<int> arr = { 4,3,2,1 };
	vector<int> answer;


	int nMin = arr[0];
	int nPos = 0;

	for (int i = 1; i < arr.size(); i++)
	{
		if (nMin > arr[i])
		{
			nMin = arr[i];
			nPos = i;
		}
	}

	if (arr.size() == 1)
	{
		answer.push_back(-1);
	}
	else
	{
		arr.erase(arr.begin() + nPos);
		answer = arr;
	}

    return 0;
}