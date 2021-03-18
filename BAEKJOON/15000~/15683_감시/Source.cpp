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
typedef pair<p, int> pi;
typedef vector<vector<int>> vmap;

//custum function
int CctvView(vmap& vMap, int nX, int nY, int nDir, int nMode)
{
	int nCount = 0;
	int nMoveX[4] = { 0, 1, 0, -1 };
	int nMoveY[4] = { 1, 0, -1, 0 };

	int nSizeX = vMap.size();
	int nSizeY = vMap[0].size();

	vector<vector<int>> vCctvMovePattern(5);
	//0 : 그대로 / 1 : 90 / 2 : 180 / 3 : 270
	vCctvMovePattern[0] = { 0 };
	vCctvMovePattern[1] = { 0, 2 };
	vCctvMovePattern[2] = { 0, 1 };
	vCctvMovePattern[3] = { 0, 1, 2 };
	vCctvMovePattern[4] = { 0, 1, 2, 3 };

	for (int i = 0; i < vCctvMovePattern[nMode].size(); i++)	//정의된 패턴대로 진행
	{
		int nNowDir = (nDir + vCctvMovePattern[nMode][i]) % 4;
		int nNowX = nX;
		int nNowY = nY;

		while (true)
		{
			if (nNowX < 0 || nNowY < 0 || nNowX >= nSizeX || nNowY >= nSizeY)
				break;
			
			const int nNowValue = vMap[nNowX][nNowY];

			if (nNowValue == 6)
				break;

			if (nNowValue == 0)
			{
				vMap[nNowX][nNowY] = -1;
				++nCount;
			}
			nNowX += nMoveX[nNowDir];
			nNowY += nMoveY[nNowDir];
		}
	}

	return nCount;
}

void BackTracking(vmap& vMap, int &nZeroCount, vector<pi>& vCCTV, int&nMin)
{
	if (vCCTV.empty())
	{
		nMin = min(nMin, nZeroCount);
		return;
	}

	vector<vector<int>> vCctvDirPattern(5);
	//0 : 그대로 / 1 : 90 / 2 : 180 / 3 : 270
	vCctvDirPattern[0] = { 0, 1, 2, 3 };
	vCctvDirPattern[1] = { 0, 1 };
	vCctvDirPattern[2] = { 0, 1, 2, 3 };
	vCctvDirPattern[3] = { 0, 1, 2, 3 };
	vCctvDirPattern[4] = { 0};

	pi pTemp = vCCTV.back();
	int nX, nY, nMode;
	nX = pTemp.first.first;
	nY = pTemp.first.second;
	nMode = pTemp.second;
	vCCTV.pop_back();
	vmap vTemp = vMap;

	for (int i = 0; i < vCctvDirPattern[nMode].size(); i++)
	{
		int nTemp = CctvView(vMap, nX, nY, vCctvDirPattern[nMode][i], nMode);
		nZeroCount -= nTemp;
		BackTracking(vMap, nZeroCount, vCCTV, nMin);
		nZeroCount += nTemp;
		vMap = vTemp;
	}

	vCCTV.push_back(pTemp);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//방향은 우 하 좌 상
	//Declaration
	int nSizeX, nSizeY, nZeroCount = 0, nMin = DEF_MAX;
	vmap vMap;
	vector<pi> vCCTV;

	//Input
	cin >> nSizeX >> nSizeY;
	vMap = vmap(nSizeX, vector<int>(nSizeY, 0));
	for (int i = 0; i < nSizeX; i++)
	{
		for (int j = 0; j < nSizeY; j++)
		{
			int nValue;
			cin >> nValue;
			if (nValue > 0 && nValue < 6)
			{
				vCCTV.push_back(pi(p(i, j), nValue - 1));
			}
			else if (nValue == 0)
				++nZeroCount;

			vMap[i][j] = nValue;
		}
	}

	//Solution
	BackTracking(vMap, nZeroCount, vCCTV, nMin);

	//Output
	cout << nMin << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}