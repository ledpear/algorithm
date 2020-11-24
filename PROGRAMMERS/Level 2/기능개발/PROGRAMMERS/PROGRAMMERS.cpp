// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;
	vector<int> progresses;
	vector<int> speeds;
	progresses.push_back(95);
	progresses.push_back(90);
	progresses.push_back(99);
	progresses.push_back(99);
	progresses.push_back(80);
	progresses.push_back(99);

	speeds.push_back(1);
	speeds.push_back(1);
	speeds.push_back(1);
	speeds.push_back(1);
	speeds.push_back(1);
	speeds.push_back(1);

	vector<int> answer;
	int nPos = 0;
	int nEndJob = 0;

	while (true)
	{
		for (int i = 0; i < progresses.size(); i++)
		{
			progresses[i] = progresses[i] + speeds[i];
			if (nPos == i && progresses[i] >= 100)
			{
				nPos++;
				nEndJob++;
			}
		}
		if (nEndJob != 0)
			answer.push_back(nEndJob);

		nEndJob = 0;

		if (nPos >= progresses.size())
			break;
	}

    return 0;
}

