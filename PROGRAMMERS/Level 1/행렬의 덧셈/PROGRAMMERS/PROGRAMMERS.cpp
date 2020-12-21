// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;
	vector<vector<int>> arr1;
	vector<vector<int>> arr2;

	vector<vector<int>> answer;

	for (int i = 0; i < arr1.size(); i++)
	{
		vector<int> temp;
		for (int j = 0; j < arr1[i].size(); j++)
		{
			temp.push_back(arr1[i][j] + arr2[i][j]);
		}
		answer.push_back(temp);
	}

    return 0;
}

