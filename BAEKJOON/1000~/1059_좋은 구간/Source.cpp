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
	int nSize, n, nCount = 0;
	cin >> nSize;
	vector<int> vArr(nSize);
	for (int i = 0; i < nSize; i++)
	{
		cin >> vArr[i];
	}

	cin >> n;

	int nMin = 1001, nMax = 0;

	for (int i = 0; i < nSize; i++)
	{
		if (n <= vArr[i] && nMin > vArr[i])
			nMin = vArr[i];
		if (n >= vArr[i] && nMax < vArr[i])
			nMax = vArr[i];
	}

	for (int i = nMax + 1; i <= n; i++)
	{
		int j;
		if (i != n)
			j = n;
		else
			j = n + 1;
		for (j; j < nMin; j++)
			nCount++;
	}

	cout << nCount << '\n';

	system("pause");

	return 0;
}