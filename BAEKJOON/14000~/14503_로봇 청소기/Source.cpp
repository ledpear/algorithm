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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int nSizeX, nSizeY;
	int nX, nY, nDir, nResult = 0, nCount = 0;
	vmap vMap, vVisit;
	int nMoveX[4] = { -1, 0, 1, 0 };
	int nMoveY[4] = { 0, 1, 0, -1 };

	//Input
	cin >> nSizeX >> nSizeY;
	cin >> nX >> nY >> nDir;
	vMap = vmap(nSizeX, vector<int>(nSizeY));
	for (int i = 0; i < nSizeX; i++)
	{
		for (int j = 0; j < nSizeY; j++)
		{
			cin >> vMap[i][j];
		}
	}
	vVisit = vMap;

	//Solution
	while (true)
	{
		if (vVisit[nX][nY] == false)
		{
			nResult++;
			vVisit[nX][nY] = true;
		}
		
		int nPosX, nPosY;

		if (nCount == 4)
		{
			nCount = 0;

			nPosX = nX - nMoveX[nDir];
			nPosY = nY - nMoveY[nDir];
			if (nPosX >= 0 && nPosX < nSizeX && nPosY >= 0 && nPosY < nSizeY && vMap[nPosX][nPosY] == false)
			{
				nX = nPosX;
				nY = nPosY;
			}
			else
				break;
		}
		else
		{
			int nNext = (nDir - 1);
			if (nNext < 0) nNext = 3;

			nPosX = nX + nMoveX[nNext];
			nPosY = nY + nMoveY[nNext];
			if (nPosX >= 0 && nPosX < nSizeX && nPosY >= 0 && nPosY < nSizeY && vVisit[nPosX][nPosY] == false)
			{
				nCount = 0;
				nX = nPosX;
				nY = nPosY;
				nDir = nNext;
			}
			else
			{
				nCount++;
				nDir = nNext;
			}
		}
	}

	//Output
	cout << nResult << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}