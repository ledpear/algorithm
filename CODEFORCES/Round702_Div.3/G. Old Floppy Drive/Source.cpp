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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nTestSize;
	cin >> nTestSize;
	for (int nTest = 0; nTest < nTestSize; nTest++)
	{
		int n, m;
		cin >> n >> m;
		vector<int> vArr(n);
		vector<int> vFind(m);
		for (int i = 0; i < n; i++)
			cin >> vArr[i];
		for (int i = 0; i < m; i++)
			cin >> vFind[i];

		vector<int> vPos(n, 0);
		vPos[0] = vArr[0];
		int nSum = vPos[0];
		int nMax = -2147483648;
		int nMin = 2147483647;
		for (int i = 1; i < n; i++)
		{
			vPos[i] = vPos[i - 1] + vArr[i];
			nSum += vPos[i];
			if (nMax < nSum)
				nMax = nSum;
			if (nMin > nSum)
				nMin = nSum;
		}

		bool Dir;

		for (int i = 0; i < m; i++)
		{
			if (nSum > 0)
			{
				if (vFind[i] < nMin)
				{
					cout << -1 << ' ';
					continue;
				}
				else
				{

				}
			}
		}
	}

	return 0;
}