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
int BFS(vmap& vMap, int nX, int nY)
{
	int nSizeX = vMap.size();
	int nSizeY = vMap[0].size();

	queue<p> qPoint;
	qPoint.push(p(nX, nY));
	
	while (qPoint.empty() == false)
	{
		const int nPosX = qPoint.back().first;
		const int nPosY = qPoint.back().second;
		const int nValue = vMap[nPosX][nPosY];
		qPoint.pop();
		if(nValue != 0)	continue;

		//이동패턴 정의
		int nMoveX[4] = { 0, 0, 1, -1 };
		int nMoveY[4] = { 1, -1, 0, 0 };


	}
}

void BackTracking(vmap& vMap, const vector<p>& vVirus, int &nBlank, int &nMax, int nCount = 0)
{
	if (nCount == 3)
	{
		vmap vSave = vMap;
	}

	int nSizeX = vMap.size();
	int nSizeY = vMap[0].size();

	for (int i = 0; i < nSizeX; i++)
	{
		for (int j = 0; j < nSizeY; j++)
		{
			if (vMap[i][j] == 0)
			{
				vMap[i][j] = 1;
				BackTracking(vMap, vVirus, nBlank, nMax, nCount + 1);
				vMap[i][j] = 0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int nSizeX, nSizeY, nBlank = 0, nMax = DEF_MIN;
	vmap vMap;
	vector<p> vVirus;

	//Input
	cin >> nSizeX >> nSizeY;
	vMap = vmap(nSizeX, vector<int>(nSizeY));
	for (int i = 0; i < nSizeX; i++)
	{
		for (int j = 0; j < nSizeY; j++)
		{
			cin >> vMap[i][j];
			if (vMap[i][j] == 0)
				++nBlank;
			else if (vMap[i][j] == 2)
				vVirus.push_back(p(i, j));
		}
	}

	//Solution


	//Output


	////////////////////////////////////
	system("pause");
	return 0;
}