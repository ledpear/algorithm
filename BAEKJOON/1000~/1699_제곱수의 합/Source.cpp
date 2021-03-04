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

	int nInput, nResult = 0;
	cin >> nInput;
	vector<int> vDP(nInput + 1);

	for (int i = 0; i <= nInput; i++)
		vDP[i] = i;
	
	for (int i = 2; i <= nInput; i++)
	{
		for (int j = 2; j * j <= i; j++)
		{
			vDP[i] = min(vDP[i], vDP[i - (j * j)] + 1);
		}
	}

	cout << vDP[nInput] << '\n';
	system("pause");
	return 0;
}