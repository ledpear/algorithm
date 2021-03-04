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
	int nInput;
	cin >> nInput;
	vector<int> vDP(10);
	for (int i = 0; i < 10; i++)
	{
		vDP[i] = i + 1;
	}
	for (int i = 1; i < nInput; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			vDP[j] = (vDP[j] + vDP[j - 1]) % 10007;
		}
	}

	cout << vDP[9] << '\n';
	system("pause");

	return 0;
}