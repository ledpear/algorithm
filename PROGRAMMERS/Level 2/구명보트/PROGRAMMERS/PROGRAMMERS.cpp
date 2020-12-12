// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int nLast = -1;
	vector<int> people = { 70,80,50};
	int limit = 100;;
	int answer = 0;

	sort(people.begin(), people.end());

	int nCount = 0;
	int nSum = 0;
	int nPos = 0;

	int nHead = 0;
	int nTail = people.size() - 1;

	while (true)
	{
		if (nHead == nTail)
		{
			++nCount;
			break;
		}
		else if (nHead > nTail)
		{
			break;
		}

		if (people[nHead] + people[nTail] > limit)
		{
			--nTail;
			++nCount;
		}
		else
		{
			++nHead;
			--nTail;
			++nCount;
		}

	}

	answer = nCount;

    return 0;
}

