// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main()
{
	vector<int> Numbers;
	map<int, int> NumberMap;
	int nCount = 0;
	cin >> nCount;
	int temp;
	int sum = 0;
	int nMax = -4001;
	int nMin = 4001;
	for (int i = 0; i < nCount; i++)
	{
		//ÀÔ·Â
		cin >> temp;

		//°è»ê
		sum += temp;
		if (nMax < temp)	nMax = temp;
		if (nMin > temp)	nMin = temp;

		//ÃÖºó°ª
		auto it = NumberMap.find(temp);
		if (it == NumberMap.end())
		{
			NumberMap[temp] = 1;
		}
		else
		{
			NumberMap[temp] = it->second + 1;
		}

		//Á¤·Ä
		Numbers.push_back(temp);
	}


	cout << round((double)sum / (double)Numbers.size()) << endl;	// »ê¼úÆò±Õ

	int nCenter = (int)((double)Numbers.size() / 2.0 + 0.5);

	sort(Numbers.begin(), Numbers.end());
	cout << Numbers[nCenter - 1] << endl;					// Áß¾Ó°ª

	int MinFirst = 9999;
	int MinSecond = 9999;
	int MaxCount = 0;
	for (auto iter = NumberMap.begin(); iter != NumberMap.end(); iter++)
	{
		if (MaxCount < iter->second)
		{
			MinFirst = iter->first;
			MinSecond = 9999;
			MaxCount = iter->second;
		}
		else if (MaxCount == iter->second)
		{
			if (MinSecond == 9999)
				MinSecond = iter->first;
		}
	}

	if(MinSecond == 9999)
		cout << MinFirst << endl;					// ÃÖºó°ª
	else
		cout << MinSecond << endl;					// ÃÖºó°ª

	cout << abs(nMax - nMin) << endl;					// ¹üÀ§

	system("pause");
    return 0;
}

