// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;
	int n;
	vector<int> arr1;
	vector<int> arr2;

	vector<string> answer;

	for (int j = 0; j < n; j++)
	{
		int temp = arr1[j];
		string strMap = "";
		for (int i = 0; i < n; i++)
		{
			if (temp % 2 == 1)
			{
				strMap = '#' + strMap;
			}
			else
			{
				strMap = ' ' + strMap;
			}
			temp /= 2;
		}
		answer.push_back(strMap);
	}

	for (int j = 0; j < n; j++)
	{
		int temp = arr2[j];
		string strMap = "";
		for (int i = n - 1; i >= 0; i--)
		{
			if (answer[j][i] == ' ')
			{
				if (temp % 2 == 1)
				{
					answer[j][i] = '#';
				}
			}
			
			temp /= 2;
		}
	}

    return 0;
}

