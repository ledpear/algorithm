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
int BackTracking(int nSizeH, int nSizeW, int nX, int nY, const int *nMoveX, const int *nMoveY, const vmap& vMap, vmap& vDP)
{
	if (nX == nSizeW - 1 && nY == nSizeH - 1)
	{
		return 1;
	}
	if (vDP[nY][nX] != -1)
	{
		return vDP[nY][nX];
	}
	vDP[nY][nX] = 0;
	for (int i = 0; i < 4; i++)
	{
		int posX, posY;
		posX = nX + nMoveX[i];
		posY = nY + nMoveY[i];

		if (posX >= 0 && posX < nSizeW && posY >= 0 && posY < nSizeH)
		{
			if (vMap[posY][posX] < vMap[nY][nX])
			{
				vDP[nY][nX] = vDP[nY][nX] + BackTracking(nSizeH, nSizeW, posX, posY, nMoveX, nMoveY, vMap, vDP);
			}
		}
	}

	return vDP[nY][nX];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//백트래킹
	//모든 루트를 백트래킹 방식으로 탐색
	//Declaration
	int nH, nW, nResult = 0;
	int nMoveX[4] = { 1, -1, 0, 0 };
	int nMoveY[4] = { 0, 0, 1, -1 };
	vmap vMap, vDP;

	//Input
	cin >> nH >> nW;
	vMap = vmap(nH, vector<int>(nW));
	vDP = vmap(nH, vector<int>(nW, -1));
	for (int i = 0; i < nH; i++)
	{
		for (int j = 0; j < nW; j++)
		{
			cin >> vMap[i][j];
		}
	}

	//Solution
	nResult = BackTracking(nH, nW, 0, 0, nMoveX, nMoveY, vMap, vDP);

	//Output
	cout << nResult << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}