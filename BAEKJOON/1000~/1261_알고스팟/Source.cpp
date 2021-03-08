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
typedef pair<p, int> point;

//custum function
template <typename T>
void tSwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int BFS01(int nW, int nH, const vmap& vMap)
{
	int nResult = 0;
	deque<point> dq;
	vmap vVisit = vmap(nH, vector<int>(nW, false));
	int moveX[4] = { 1, -1, 0, 0 };
	int moveY[4] = { 0, 0, 1, -1 };

	dq.push_front(point(p(0, 0), 0));
	while (!dq.empty())
	{
		int nowX, nowY, nCost;
		nowX = dq.front().first.first;
		nowY = dq.front().first.second;
		nCost = dq.front().second;
		dq.pop_front();

		if (nowX == nW - 1 && nowY == nH - 1)
		{
			nResult = nCost;
			break;
		}

		if(vVisit[nowY][nowX]) continue;
		vVisit[nowY][nowX] = true;

		for (int i = 0; i < 4; i++)
		{
			int posX, posY;
			posX = nowX + moveX[i];
			posY = nowY + moveY[i];
			if (posX >= 0 && posX < nW && posY >= 0 && posY < nH)
			{
				if (vMap[posY][posX] == 0)
					dq.push_front(point(p(posX, posY), nCost));
				else
					dq.push_back(point(p(posX, posY), nCost + 1));
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
	int nW, nH;
	vmap vMap;

	//Input
	cin >> nW >> nH;
	vMap = vmap(nH, vector<int>(nW));
	for (int i = 0; i < nH; i++)
	{
		string strTemp;
		cin >> strTemp;
		for (int j = 0; j < nW; j++)
		{
			vMap[i][j] = strTemp[j] - '0';
		}
	}

	//Solution

	//Output
	cout << BFS01(nW, nH, vMap) << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}