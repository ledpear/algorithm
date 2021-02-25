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
typedef vector<vector<short>> vmap;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int nX, nY, nFind = 0;
	bool bResult = false;
	cin >> nX >> nY;
	vmap vMap = vmap(nX, vector<short>(nY, 0));

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
	q.push(pos(p(0, 0), false));

	while (!q.empty())
	{
		queue<pos> qTemp;

		while (!q.empty()) 
		{
			pos posTemp = q.front();
			q.pop();
			int nPosX, nPosY;
			nPosX = posTemp.first.first;
			nPosY = posTemp.first.second;

			if (nPosX == nX - 1 && nPosY == nY - 1)
			{
				bResult = true;
				break;
			}

			vMap[nPosX][nPosY] = -1;

			if (posTemp.second)	//벽을 이미 부섰을 경우
			{
				if (nPosX > 0 && vMap[nPosX - 1][nPosY] == 0)
					qTemp.push(pos(p(nPosX - 1, nPosY), true));
				if (nPosX < nX - 1 && vMap[nPosX + 1][nPosY] == 0)
					qTemp.push(pos(p(nPosX + 1, nPosY), true));

				if (nPosY > 0 && vMap[nPosX][nPosY - 1] == 0)
					qTemp.push(pos(p(nPosX, nPosY - 1), true));
				if (nPosY < nY - 1 && vMap[nPosX][nPosY + 1] == 0)
					qTemp.push(pos(p(nPosX, nPosY + 1), true));
			}
			else//벽을 부수지 않은 경우
			{
				if (nPosX > 0)
				{
					if (vMap[nPosX - 1][nPosY] == 0)
						qTemp.push(pos(p(nPosX - 1, nPosY), false));
					else if (vMap[nPosX - 1][nPosY] == 1)
						qTemp.push(pos(p(nPosX - 1, nPosY), true));
				}
				if (nPosX < nX - 1)
				{
					if (vMap[nPosX + 1][nPosY] == 0)
						qTemp.push(pos(p(nPosX + 1, nPosY), false));
					else if (vMap[nPosX + 1][nPosY] == 1)
						qTemp.push(pos(p(nPosX + 1, nPosY), true));
				}
				if (nPosY > 0)
				{
					if (vMap[nPosX][nPosY - 1] == 0)
						qTemp.push(pos(p(nPosX, nPosY - 1), false));
					else if (vMap[nPosX][nPosY - 1] == 1)
						qTemp.push(pos(p(nPosX, nPosY - 1), true));
				}
				if (nPosY < nY - 1)
				{
					if (vMap[nPosX][nPosY + 1] == 0)
						qTemp.push(pos(p(nPosX, nPosY + 1), false));
					else if (vMap[nPosX][nPosY + 1] == 1)
						qTemp.push(pos(p(nPosX, nPosY + 1), true));
				}
			}
		}

		if (qTemp.empty())
		{
			if (bResult)
			{
				cout << nFind + 1 << '\n';
				break;
			}
			else
			{
				cout << "-1\n";
				break;
			}
		}			
		else
			q = qTemp;

		nFind++;
	}

	system("pause");
	return 0;
}