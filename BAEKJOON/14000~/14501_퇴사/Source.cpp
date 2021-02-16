#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
typedef pair<int, int> p;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nSize;
	cin >> nSize;
	vector<p> vArr(nSize);
	vector<int> vDP(nSize + 1, 0);
	int nMax = 0;
	for (int i = 0; i < nSize; i++)
	{
		cin >> vArr[i].first >> vArr[i].second;
	}

	for (int i = 0; i < nSize; i++)
	{
		for (int j = i + vArr[i].first; j <= nSize; j++)
		{
			vDP[j] = max(vDP[j], vArr[i].second + vDP[i]);
		}
	}

	cout << vDP[nSize] << '\n';

	return 0;
}