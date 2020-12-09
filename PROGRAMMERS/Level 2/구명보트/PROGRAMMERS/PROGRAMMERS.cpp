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
	vector<int> people = { 70,50,80,50};
	int limit = 100;;
	int answer = 0;

	sort(people.begin(), people.end());

	int nCount = 0;
	int nSum = 0;
	int nPos = 0;

	while (true)
	{
		nSum = people[0];
		nPos = people.size();

		while (true)
		{
			--nPos;
			if (nPos == 0)
			{
				break;
			}
			else if (nSum + people[nPos] <= limit)
			{
				break;
			}
		}

		if (nPos == 0)
		{
			people.erase(people.begin());
		}
		else
		{
			people.erase(people.begin() + nPos);
			people.erase(people.begin());
		}
		nCount++;

		if (people.size() == 0) break;
	}

	answer = nCount;

    return 0;
}

