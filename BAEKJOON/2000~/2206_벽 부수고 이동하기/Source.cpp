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
typedef pair<int, int> p;
typedef pair<p, p> pos;
typedef vector<vector<char>> vmap;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int nX, nY, nResult = -1;
	bool bResult = false;
	cin >> nX >> nY;
	vmap vMap = vmap(nX, vector<char>(nY, 0));
	vector<vector<vector<int>>> vVisit = vector<vector<vector<int>>>(nX, vector<vector<int>>(nY, vector<int>(2, false)));
	int dX[4] = { 1, -1, 0, 0 };
	int dY[4] = { 0, 0, 1, -1 };

	string strTemp;
	for (int i = 0; i < nX; i++)
	{
		cin >> strTemp;
		for (int j = 0; j < nY; j++)
		{
			vMap[i][j] = strTemp[j] - '0';
		}
	}

	queue<pos> q;
	q.push(pos(p(0, 0), p(0, 1)));	//x, y, broken, count
	vVisit[0][0][0] = true;

	int nPosX, nPosY, nBroken, nCount;

	while (!q.empty())
	{
		nPosX = q.front().first.first;
		nPosY = q.front().first.second;
		nBroken = q.front().second.first;
		nCount = q.front().second.second;
		q.pop();

		if (nPosX == nX - 1 && nPosY == nY - 1)
		{
			nResult = nCount;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nMoveX, nMoveY;
			nMoveX = nPosX + dX[i];
			nMoveY = nPosY + dY[i];

			if (nMoveX >= 0 && nMoveX < nX && nMoveY >= 0 && nMoveY < nY)
			{
				if (nBroken == false && vMap[nMoveX][nMoveY] == 1)
				{
					vVisit[nMoveX][nMoveY][nBroken + 1] = true;
					q.push(pos(p(nMoveX, nMoveY), p(true, nCount + 1)));

				}
				else if (vMap[nMoveX][nMoveY] == 0 && vVisit[nMoveX][nMoveY][nBroken] == false)
				{
					vVisit[nMoveX][nMoveY][nBroken] = true;
					q.push(pos(p(nMoveX, nMoveY), p(nBroken, nCount + 1)));
				}
			}
		}
	}

	cout << nResult << '\n';

	return 0;
}