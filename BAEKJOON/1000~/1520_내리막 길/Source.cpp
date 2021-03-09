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

int nSizeH, nSizeW;
const int nMoveX[4] = { 1, -1, 0, 0 };
const int nMoveY[4] = { 0, 0, 1, -1 };
vmap vMap, vDP;
//custum function
int BackTracking( int nX, int nY)
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
				vDP[nY][nX] = vDP[nY][nX] + BackTracking(posX, posY);
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
	int nResult = 0;

	//Input
	cin >> nSizeH >> nSizeW;
	vMap = vmap(nSizeH, vector<int>(nSizeW));
	vDP = vmap(nSizeH, vector<int>(nSizeW, -1));
	for (int i = 0; i < nSizeH; i++)
	{
		for (int j = 0; j < nSizeW; j++)
		{
			cin >> vMap[i][j];
		}
	}

	//Solution
	nResult = BackTracking(0, 0);

	//Output
	cout << nResult << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}