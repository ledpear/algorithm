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

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

typedef unsigned long long ull;
typedef pair<ull, ull> p;
typedef vector<vector<int>> vmap;

//custum function
bool DFS(const vmap& vMap, vmap& vVisit, int nX, int nY, int nMin, int nMax, vector<p> &vList, int &nSum)
{
	if (vVisit[nX][nY] == true)
		return false;

	vVisit[nX][nY] = true;
	int nSize = vMap.size();
	int nMoveX[4] = { 1, -1, 0, 0 };
	int nMoveY[4] = { 0, 0, 1, -1 };
	bool bResult = false;
	vList.push_back(p(nX, nY));
	nSum += vMap[nX][nY];

	for (int i = 0; i < 4; i++)
	{
		int nPosX = nX + nMoveX[i];
		int nPosY = nY + nMoveY[i];

		if (nPosX >= 0 && nPosY >= 0 && nPosX < nSize && nPosY < nSize)
		{
			if (vVisit[nPosX][nPosY] == false)
			{
				int nDiff = abs(vMap[nX][nY] - vMap[nPosX][nPosY]);
				if (nMin <= nDiff && nMax >= nDiff)
				{
					bResult = true;
					DFS(vMap, vVisit, nPosX, nPosY, nMin, nMax, vList, nSum);
				}
			}			
		}
	}
	return bResult;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int nSize, nCount = 0, nSum = 0;
	int nMin, nMax;
	vmap vMap, vVisit;
	vector<p> vList;

	//Input
	cin >> nSize >> nMin >> nMax;
	vMap = vmap(nSize, vector<int>(nSize));
	vVisit = vMap;
	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
			cin >> vMap[i][j];
	}

	//Solution
	while (true)
	{
		bool bResult = false;
		vVisit = vmap(nSize, vector<int>(nSize, false));
		for (int i = 0; i < nSize; i++)
		{
			for (int j = 0; j < nSize; j++)
			{
				if (vVisit[i][j] == true)	continue;

				vList.clear();
				nSum = 0;
				if (DFS(vMap, vVisit, i, j, nMin, nMax, vList, nSum) == true)
				{
					bResult = true;
					

					int nAvg = nSum / vList.size();
					for (int k = 0; k < vList.size(); k++)
					{
						vMap[vList[k].first][vList[k].second] = nAvg;
					}
				}
			}
		}
		if (bResult == false) break;
		else ++nCount;
	}	

	//Output
	cout << nCount << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}