// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> citations;
	citations.push_back(3);
	citations.push_back(0);
	citations.push_back(6);
	citations.push_back(1);
	citations.push_back(5);
	citations.push_back(1);

	sort(citations.begin(), citations.end());

	int answer = 0;
	int pos = 0;

	if (citations.size() == 1 && citations[0] == 1)
		return 1;

	for (int i = 0; i < citations.size(); i++)
	{
		if (citations[i] < i)
		{
			pos = i - 1;
			break;
		}

		if (citations[i] > citations.size() - i)
		{
			pos = i - 1;
			break;
		}
	}
	
	answer = citations[pos];

	system("pause");
	return answer;
}

