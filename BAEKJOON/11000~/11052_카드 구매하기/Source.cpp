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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nSize;
	cin >> nSize;
	vector<int> vArr(nSize);
	vector<vector<int>> vDP(nSize + 1, vector<int>(nSize + 1, 0));
	
	for (int i = 0; i < nSize; i++)
	{
		cin >> vArr[i];
	}

	for (int i = 1; i <= nSize; i++)
	{
		vDP[1][i] = vArr[0] * i;
	}

	for (int i = 2; i <= nSize; i++)
	{
		for (int j = 0; j <= nSize; j++)
		{
			if (j < i)
				vDP[i][j] = vDP[i - 1][j];
			else
				vDP[i][j] = max(vDP[i - 1][j], vArr[i - 1] + vDP[i][j - i]);
		}
	}

	cout << vDP[nSize][nSize] << '\n';
	system("pause");

	return 0;
}