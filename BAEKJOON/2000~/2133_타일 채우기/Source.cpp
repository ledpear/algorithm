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

	//입력값이 홀수이면 결과는 0

	int nInput;
	vector<int> vDP(31, 0);
	cin >> nInput;

	vDP[0] = 1;
	vDP[1] = 0;
	vDP[2] = 3;
	vDP[3] = 0;

	for (int i = 4; i <= nInput; i += 2)
	{
		vDP[i] = vDP[i - 2] * 3;
		for (int j = 4; j <= i; j += 2)
		{
			vDP[i] += vDP[i - j] * 2;
		}
	}

	cout << vDP[nInput] << '\n';

	system("pause");

	return 0;
}