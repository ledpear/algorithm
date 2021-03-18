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
bool DFS(const vmap& vMap, vmap& vVisit, int nX, int nY)
{
	//방문처리
	if (vVisit[nX][nY] == true) return false;
	vVisit[nX][nY] = true;

	//크기 정의
	int nSizeX = vMap.size();
	int nSizeY = vMap[0].size();

	//이동패턴 정의
	int nMoveX[4] = { 0, 0, 1, -1 };
	int nMoveY[4] = { 1, -1, 0, 0 };

	//이동할 수 있는 곳은 이동
	for (int i = 0; i < 4; i++)
	{
		int nPosX = nX + nMoveX[i];
		int nPosY = nY + nMoveY[i];

		//범위 및 방문 예외처리
		if (nPosX >= 0 && nPosX < nSizeX && nPosY >= 0 && nPosY < nSizeY && vVisit[nPosX][nPosY] == false)
		{
			//조건
			int nPosValue = vMap[nPosX][nPosY];
			if (nPosValue != 0)
			{
				DFS(vMap, vVisit, nPosX, nPosY);
			}
		}
	}
	return true;
}

void IceMelt(vmap& vMap, vector<p>& vIce)
{
	int nList = 0;

	int nMoveX[4] = { 0, 0, 1, -1 };
	int nMoveY[4] = { 1, -1, 0, 0 };

	vmap vTemp = vMap;

	while (nList != vIce.size())
	{
		bool bErase = false;

		int nNowX = vIce[nList].first;
		int nNowY = vIce[nList].second;

		for (int i = 0; i < 4; i++)
		{
			int nPosX = nNowX + nMoveX[i];
			int nPosY = nNowY + nMoveY[i];

			if (vTemp[nPosX][nPosY] == 0)
				--vMap[nNowX][nNowY];

			if (vMap[nNowX][nNowY] <= 0)
			{
				vIce.erase(vIce.begin() + nList);
				bErase = true;
				break;
			}
		}

		if (bErase == false) nList++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int nSizeX, nSizeY, nCount = 0;
	vmap vMap;
	vector<p> vIce;

	//Input
	cin >> nSizeX >> nSizeY;
	vMap = vmap(nSizeX, vector<int>(nSizeY));
	for (int i = 0; i < nSizeX; i++)
	{
		for (int j = 0; j < nSizeY; j++)
		{
			cin >> vMap[i][j];
			if (vMap[i][j] != 0)
				vIce.push_back(p(i, j));
		}
	}

	//Solution
	while (true)
	{
		if (vIce.empty())	//다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 0 출력
		{
			nCount = 0;
			break;
		}

		nCount++;

		int nIceCount = 0;
		vmap vVisit(nSizeX, vector<int>(nSizeY, 0));

		IceMelt(vMap, vIce);
		for (int i = 0; i < vIce.size(); i++)
		{
			int nPosX = vIce[i].first;
			int nPosY = vIce[i].second;

			if (vVisit[nPosX][nPosY] == true)	continue;

			if (DFS(vMap, vVisit, nPosX, nPosY) == true)
				++nIceCount;
			if (nIceCount >= 2)
				break;
		}
		if (nIceCount >= 2)
			break;
	}

	//Output
	cout << nCount << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}