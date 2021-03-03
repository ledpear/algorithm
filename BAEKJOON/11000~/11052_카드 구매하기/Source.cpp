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
	vector<int> vArr(nSize + 1);
	vector<int> vDP(nSize + 1, 0);
	
	for (int i = 1; i <= nSize; i++)
	{
		cin >> vArr[i];
	}

	for (int i = 1; i <= nSize; i++)
	{
		vDP[i] = vArr[1] * i;
	}

	for (int i = 2; i <= nSize; i++)
	{
		for (int j = i; j <= nSize; j++)
		{
			vDP[j] = max(vDP[j], vArr[i] + vDP[j - i]);
		}
	}

	cout << vDP[nSize]<< '\n';
	system("pause");

	return 0;
}