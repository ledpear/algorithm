#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <functional>

using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> p;

ull dist(p a, p b)
{
	ull nResult = 0;
	nResult += abs((int)a.first - (int)b.first);
	nResult += abs((int)a.second - (int)b.second);
	return nResult;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nTestSize;
	cin >> nTestSize;

	for (int nTest = 0; nTest < nTestSize; nTest++)
	{
		ull nSize, nMax_X, nMax_Y, nMin_X, nMin_Y;
		nMax_X = 0;
		nMax_Y = 0;
		nMin_X = 1000000001;
		nMin_Y = 1000000001;
		cin >> nSize;
		vector<p> vArr(nSize);

		for (int i = 0; i < nSize; i++)
		{
			cin >> vArr[i].first >> vArr[i].second;
			if (nMax_X < vArr[i].first)
				nMax_X = vArr[i].first;
			if (nMax_Y < vArr[i].second)
				nMax_Y = vArr[i].second;
			if (nMin_X > vArr[i].first)
				nMin_X = vArr[i].first;
			if (nMin_Y > vArr[i].second)
				nMin_Y = vArr[i].second;
		}

		p pCenter;
		pCenter.first = nMin_X + ((nMax_X - nMin_X) / 2);
		pCenter.second = nMin_Y + ((nMax_Y - nMin_Y) / 2);


		ull nCount = 0;
		ull nMin = 2000000001;
		ull nDist = 0;
		p temp;
		
		for (int i = (int)pCenter.first - 1; i <= (int)pCenter.first + 1; i++)
		{
			for (int j = (int)pCenter.second - 1; j <= (int)pCenter.second + 1; j++)
			{
				if(i < 0 || j < 0)
					continue;

				nDist = 0;
				temp.first = i;
				temp.second = j;
				for (int k = 0; k < nSize; k++)
				{
					nDist += dist(temp, vArr[k]);
				}		
				if (nMin == nDist)
					nCount++;
				else if (nMin > nDist)
				{
					nCount = 1;
					nMin = nDist;
				}
			}
		}

		cout << nCount << '\n';
	}

	system("pause");

	return 0;
}