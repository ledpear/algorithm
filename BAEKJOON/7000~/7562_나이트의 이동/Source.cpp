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
typedef vector<vector<int>> vmap;

typedef pair<p, ull> point;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nTestCase;
	cin >> nTestCase;

	const int nMoveX[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	const int nMoveY[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

	for (int nTest = 0; nTest < nTestCase; nTest++)
	{
		int nSize, nStartX, nStartY, nTargetX, nTargetY;
		cin >> nSize;
		cin >> nStartX >> nStartY;
		cin >> nTargetX >> nTargetY;
		vmap vMap = vmap(nSize, vector<int>(nSize, false));
		queue<point> q;
		q.push(point(p(nStartX, nStartY), 0));

		vMap[nStartX][nStartY] = true;

		while (true)
		{
			int posX, posY, count;
			posX = q.front().first.first;
			posY = q.front().first.second;
			count = q.front().second;
			q.pop();

			if (posX == nTargetX && posY == nTargetY)
			{
				cout << count << '\n';
				break;
			}
			
			for (int i = 0; i < 8; i++)
			{
				if (posX + nMoveX[i] < nSize && posX + nMoveX[i] >= 0 && posY + nMoveY[i] < nSize && posY + nMoveY[i] >= 0 && vMap[posX + nMoveX[i]][posY + nMoveY[i]] == false)
				{
					vMap[posX + nMoveX[i]][posY + nMoveY[i]] = true;
					q.push(point(p(posX + nMoveX[i], posY + nMoveY[i]), count + 1));
				}
			}
		}
	}

	system("pause");

	return 0;
}