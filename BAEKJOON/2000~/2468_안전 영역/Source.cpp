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
void DFS_Sol(int nSize, const vmap& vMap, vmap& vVisit, int* nMoveX, int* nMoveY, int nTarget, int nPosX, int nPosY)
{
	vVisit[nPosX][nPosY] = true;
	for (int i = 0; i < 4; i++)
	{
		int nMovePosX, nMovePosY;
		nMovePosX = nPosX + nMoveX[i];
		nMovePosY = nPosY + nMoveY[i];
		if (nMovePosX >= 0 && nMovePosX < nSize && nMovePosY >= 0 && nMovePosY < nSize && 
			vMap[nMovePosX][nMovePosY] > nTarget && vVisit[nMovePosX][nMovePosY] == false)
		{
			DFS_Sol(nSize, vMap, vVisit, nMoveX, nMoveY, nTarget, nMovePosX, nMovePosY);
		}
	}
}

int DFS(int nSize, const vmap& vMap, int nTarget)
{
	int nResult = 0;
	vmap vVisit = vmap(nSize, vector<int>(nSize, false));
	int nMoveX[4] = { 1, -1, 0, 0 };
	int nMoveY[4] = { 0, 0, 1, -1 };

	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			if (!vVisit[i][j] && vMap[i][j] > nTarget)
			{
				DFS_Sol(nSize, vMap, vVisit, nMoveX, nMoveY, nTarget, i, j);
				nResult++;
			}				
		}
	}
	return nResult;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int nSize, nMax = DEF_MIN, nMin = DEF_MAX, nResult = 1;
	vmap vMap, vVisit;

	//Input
	cin >> nSize;
	vMap = vmap(nSize, vector<int>(nSize));
	
	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			cin >> vMap[i][j];
			nMax = max(nMax, vMap[i][j]);
			nMin  = min(nMin, vMap[i][j]);
		}
	}

	//Solution
	for (int i = nMin; i < nMax; i++)
	{
		
		nResult = max(nResult, DFS(nSize, vMap, i));
	}

	//Output
	cout << nResult << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}