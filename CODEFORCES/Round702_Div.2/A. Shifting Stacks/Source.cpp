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
	vector<int> vDP(101, 1000000001);
	vDP[0] = 0;

	for (int nTest = 0; nTest < nTestSize; nTest++)
	{
		ull nSize, nTemp, nSum = 0;
		bool bResult = true;
		cin >> nSize;

		for (int i = 0; i < nSize; i++)
		{
			cin >> nTemp;
			nSum += nTemp;

			if (vDP[i] == 1000000001)
				vDP[i] = vDP[i - 1] + i;

			if (nSum < vDP[i])
			{
				bResult = false;
			}
		}

		if (bResult)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	system("pause");
	return 0;
}