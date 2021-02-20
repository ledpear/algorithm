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

void DFS(int x, int y, int nSize, vmap &vMap, vector<int> &vResult, bool bFirst = false)
{
	if (x < 0 || x >= nSize || y < 0 || y >= nSize)
		return;

	if (vMap[x][y] == 1)
	{
		vMap[x][y] = 2;
		if (bFirst)
			vResult.push_back(0);
		vResult.back()++;

		DFS(x + 1, y, nSize, vMap, vResult);
		DFS(x, y + 1, nSize, vMap, vResult);
		DFS(x - 1, y, nSize, vMap, vResult);
		DFS(x, y - 1, nSize, vMap, vResult);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nSize;
	cin >> nSize;
	vector<vector<int>> vMap(nSize, vector<int>(nSize));
	vector<int> vResult;
	string strTemp;
	for (int i = 0; i < nSize; i++)
	{
		cin >> strTemp;
		for (int j = 0; j < nSize; j++)
		{
			vMap[i][j] = strTemp[j] - '0';
		}
	}

	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			DFS(i, j, nSize, vMap, vResult, true);
		}
	}

	sort(vResult.begin(), vResult.end());
	cout << vResult.size() << '\n';
	for (int i = 0; i < vResult.size(); i++)
	{
		cout << vResult[i] << '\n';
	}

	system("pause");

	return 0;
}