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
#include <functional>

using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> p;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nTestSize;
	cin >> nTestSize;

	for (int nTest = 0; nTest < nTestSize; nTest++)
	{
		int nSize;
		cin >> nSize;
		vector<vector<char>> vArr(nSize, vector<char>(nSize));
		vector<p> vPoint;

		for (int i = 0; i < nSize; i++)
		{
			string temp;
			cin >> temp;
			for (int j = 0; j < nSize; ++j)
			{
				vArr[i][j] = temp[j];
				if (vArr[i][j] == '*')
				{
					vPoint.push_back(p(i, j));
				}
			}
		}

		if (vPoint[0].first != vPoint[1].first && vPoint[0].second != vPoint[1].second)
		{
			vArr[vPoint[0].first][vPoint[1].second] = '*';
			vArr[vPoint[1].first][vPoint[0].second] = '*';
		}
		else if (vPoint[0].first == vPoint[1].first)
		{
			int pos = vPoint[0].first;
			if (pos - 1 >= 0)
			{
				vArr[pos - 1][vPoint[1].second] = '*';
				vArr[pos - 1][vPoint[0].second] = '*';
			}
			else if(pos + 1 < nSize)
			{
				vArr[pos + 1][vPoint[1].second] = '*';
				vArr[pos + 1][vPoint[0].second] = '*';
			}
		}
		else if (vPoint[0].second == vPoint[1].second)
		{
			int pos = vPoint[0].second;
			if (pos - 1 >= 0)
			{
				vArr[vPoint[0].first][pos - 1] = '*';
				vArr[vPoint[1].first][pos - 1] = '*';
			}
			else if (pos + 1 < nSize)
			{
				vArr[vPoint[0].first][pos + 1] = '*';
				vArr[vPoint[1].first][pos + 1] = '*';
			}
		}

		for (int i = 0; i < nSize; i++)
		{
			for (int j = 0; j < nSize; ++j)
			{
				cout << vArr[i][j];
			}
			cout << '\n';
		}
	}

	system("pause");

	return 0;
}