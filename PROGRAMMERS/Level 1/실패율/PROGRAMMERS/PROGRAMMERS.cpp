// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second > b.second;
}

int main()
{
	int nLast = -1;
	int N = 5;
	vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };

	int nPlayerSize = stages.size();

	vector<int> NowPlayerPosition;
	for (int i = 1; i <= N; i++)
	{
		int pos = 0;
		int Players = 0;
		while (true)
		{
			if (stages[pos] == i)
			{
				Players++;
				stages.erase(stages.begin() + pos);
			}
			else
			{
				pos++;
			}

			if (pos >= stages.size())
				break;
		}

		NowPlayerPosition.push_back(Players);
	}

	vector<pair<int, double>> FailRate;
	for (int i = 0; i < N; i++)
	{
		pair<int, double> TempPair;
		TempPair.first = i + 1;
		if (NowPlayerPosition[i] == 0)
		{			
			TempPair.second = 0;
			
		}
		else
		{
			TempPair.second = (double)NowPlayerPosition[i] / (double)nPlayerSize;
		}
			
		FailRate.push_back(TempPair);
		nPlayerSize -= NowPlayerPosition[i];
	}

	sort(FailRate.begin(), FailRate.end(), compare);
	vector<int> answer;

	for (int i = 0; i < FailRate.size(); i++)
	{
		answer.push_back(FailRate[i].first);
	}

    return 0;
}

