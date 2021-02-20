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
typedef pair<ull, ull> p;
typedef pair<p, int> pos;
typedef vector<vector<int>> vmap;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nX, nY;
	cin >> nX >> nY;
	vmap vMap = vmap(nX, vector<int>(nY));
	vmap vVisit;
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
	q.push(pos(p(0, 0), 1));
	int nCount = 0;
	
	while (!q.empty())
	{
		pos Pos = q.front();
		int nPosX, nPosY;
		nPosX = Pos.first.first;
		nPosY = Pos.first.second;

		q.pop();

		if (nPosX == nX - 1 && nPosY == nY - 1)
		{
			cout << Pos.second << '\n';
			break;
		}
		
		if (vMap[nPosX][nPosY] == 1)
		{
			vMap[Pos.first.first][Pos.first.second] = -1;

			Pos.second++;
			
			if (nPosX != 0)
				q.push(pos(p(nPosX - 1, nPosY), Pos.second));
			if (nPosY != 0)
				q.push(pos(p(nPosX, nPosY - 1), Pos.second));
			if (nPosX != nX - 1)
				q.push(pos(p(nPosX + 1, nPosY), Pos.second));
			if (nPosY != nY - 1)
				q.push(pos(p(nPosX, nPosY + 1), Pos.second));
		}
	}
	system("pause");

	return 0;
}