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
typedef unsigned long long ull;
typedef pair<short, short> p;
typedef pair<p, bool> pos;
typedef vector<vector<int>> vmap;

void DFS(short nPosX, short nPosY, short count, vmap &vMap, vmap &vScore, bool bCrush)
{
	int nX = vMap.size();
	int nY = vMap[0].size();
	
	vScore[nPosX][nPosY] = count;

	if (nPosX == vMap.size() - 1 && nPosY == vMap[0].size() - 1)
	{
		return;
	}

	if (bCrush)	//벽을 이미 부섰을 경우
	{
		if (nPosY < nY - 1 && vMap[nPosX][nPosY + 1] == 0 && vScore[nPosX][nPosY + 1] > count + 1)
			DFS(nPosX, nPosY + 1, count + 1, vMap, vScore, true);

		if (nPosX < nX - 1 && vMap[nPosX + 1][nPosY] == 0 && vScore[nPosX + 1][nPosY] > count + 1)
			DFS(nPosX + 1, nPosY, count + 1, vMap, vScore, true);

		if (nPosX > 0 && vMap[nPosX - 1][nPosY] == 0 && vScore[nPosX - 1][nPosY] > count + 1)
			DFS(nPosX - 1, nPosY, count + 1, vMap, vScore, true);

		if (nPosY > 0 && vMap[nPosX][nPosY - 1] == 0 && vScore[nPosX][nPosY - 1] > count + 1)
			DFS(nPosX, nPosY - 1, count + 1, vMap, vScore, true);

		
	}
	else//벽을 부수지 않은 경우
	{
		if (nPosY < nY - 1 && vScore[nPosX][nPosY + 1] > count + 1)
		{
			if (vMap[nPosX][nPosY + 1] == 0)
				DFS(nPosX, nPosY + 1, count + 1, vMap, vScore, false);
			else if (vMap[nPosX][nPosY + 1] == 1)
				DFS(nPosX, nPosY + 1, count + 1, vMap, vScore, true);
		}
		if (nPosX < nX - 1 && vScore[nPosX + 1][nPosY] > count + 1)
		{
			if (vMap[nPosX + 1][nPosY] == 0)
				DFS(nPosX + 1, nPosY, count + 1, vMap, vScore, false);
			else if (vMap[nPosX + 1][nPosY] == 1)
				DFS(nPosX + 1, nPosY, count + 1, vMap, vScore, true);
		}

		if (nPosX > 0 && vScore[nPosX - 1][nPosY] > count + 1)
		{
			if (vMap[nPosX - 1][nPosY] == 0)
				DFS(nPosX - 1, nPosY, count + 1, vMap, vScore, false);
			else if (vMap[nPosX - 1][nPosY] == 1)
				DFS(nPosX - 1, nPosY, count + 1, vMap, vScore, true);
		}
		
		if (nPosY > 0 && vScore[nPosX][nPosY - 1] > count + 1)
		{
			if (vMap[nPosX][nPosY - 1] == 0)
				DFS(nPosX, nPosY - 1, count + 1, vMap, vScore, false);
			else if (vMap[nPosX][nPosY - 1] == 1)
				DFS(nPosX, nPosY - 1, count + 1, vMap, vScore, true);
		}
		
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int nX, nY, nFind = 987654321;
	bool bResult = false;
	cin >> nX >> nY;
	vmap vMap = vmap(nX, vector<int>(nY, 0));
	vmap vScore = vmap(nX, vector<int>(nY, 987654321));

	string strTemp;
	for (int i = 0; i < nX; i++)
	{
		cin >> strTemp;
		for (int j = 0; j < nY; j++)
		{
			vMap[i][j] = strTemp[j] - '0';
		}
	}

	DFS(0, 0, 1, vMap, vScore, false);
	if (vScore[nX - 1][nY - 1] == 987654321)
		cout << "-1\n";
	else
		cout << vScore[nX - 1][nY - 1] << '\n';

	system("pause");
	return 0;
}