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
void BackTracking(int nSizeH, int nSizeW, int nX, int nY, const int *nMoveX, const int *nMoveY, const vmap& vMap, vmap& vVisit, int& nScore)
{
	if (nX == nSizeW - 1 && nY == nSizeH - 1)
	{
		nScore++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int posX, posY;
		posX = nX + nMoveX[i];
		posY = nY + nMoveY[i];

		if (posX >= 0 && posX < nSizeW && posY >= 0 && posY < nSizeH && vVisit[posY][posX] == false)
		{
			if (vMap[posY][posX] < vMap[nY][nX])
			{
				vVisit[posY][posX] = true;
				BackTracking(nSizeH, nSizeW, posX, posY, nMoveX, nMoveY, vMap, vVisit, nScore);
				vVisit[posY][posX] = false;
			}
		}
	}
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
	vmap vMap, vVisit;

	//Input
	cin >> nH >> nW;
	vMap = vmap(nH, vector<int>(nW));
	vVisit = vmap(nH, vector<int>(nW, false));
	for (int i = 0; i < nH; i++)
	{
		for (int j = 0; j < nW; j++)
		{
			cin >> vMap[i][j];
		}
	}

	//Solution
	BackTracking(nH, nW, 0, 0, nMoveX, nMoveY, vMap, vVisit, nResult);

	//Output
	cout << nResult << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}