// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> arr;
	int divisor;
	vector<int> answer;

	arr.push_back(2);
	arr.push_back(36);
	arr.push_back(1);
	arr.push_back(50);
	arr.push_back(8);

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] % divisor == 0)
			answer.push_back(arr[i]);
	}

	sort(answer.begin(), answer.end());

	if (answer.size() == 0)
		return -1;

	return 0;
}

