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

	int cost, count, now;
	cin >> cost >> count >> now;

	int nResult = cost * count - now;

	if (nResult <= 0)
		cout << "0\n";
	else
		cout << nResult << '\n';

	system("pause");

	return 0;
}