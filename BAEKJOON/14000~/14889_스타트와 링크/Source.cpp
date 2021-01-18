#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

vector<vector<int>> vMap;
vector<bool> vFind;
int nPeople;
int nSize;
int nMin = 2147483647;

void BackTracking(int count, int nLast)
{
	if (nMin == 0)
		return;
	else if (count == nPeople)
	{
		vector<int> vStart, vLink;
		for (int i = 0; i < nSize; i++)
		{
			if (vFind[i])
				vStart.push_back(i);
			else
				vLink.push_back(i);
		}

		int nStartSum = 0;
		int nLinkSum = 0;

		for (int i = 0; i < nPeople - 1; i++)
		{
			for (int j = i + 1; j < nPeople; j++)
			{
				nStartSum += (vMap[vStart[i]][vStart[j]] + vMap[vStart[j]][vStart[i]]);
				nLinkSum += (vMap[vLink[i]][vLink[j]] + vMap[vLink[j]][vLink[i]]);
			}
		}

		if (nMin > abs(nStartSum - nLinkSum))
		{
			nMin = abs(nStartSum - nLinkSum);
		}
	}
	else
	{
		for (int i = nLast + 1; i < nSize - (nPeople - count); i++)
		{
			if (!vFind[i])
			{
				vFind[i] = true;
				BackTracking(count + 1, i);
				vFind[i] = false;
			}			
		}
	}
}

int main()
{
	int input;
	cin >> input;
	nPeople = input / 2;
	nSize = input;
	vMap = vector<vector<int>>(input, vector<int>(input));
	vFind = vector<bool>(input, false);

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
			cin >> vMap[i][j];
	}

	BackTracking(0, -1);

	cout << nMin << "\n";

	return 0;
}