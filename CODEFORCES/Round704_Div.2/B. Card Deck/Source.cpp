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

	for (int nTest = 0; nTest < nTestSize; nTest++)
	{
		int nSize, nMaxPos, nTarget;
		cin >> nSize;
		vector<ull> vArr(nSize), vResult;
		ull uMax = 0;

		for (int i = 0; i < nSize; i++)
		{
			cin >> vArr[i];
			if (uMax < vArr[i])
			{
				uMax = vArr[i];
				nMaxPos = i;
			}
		}

		nTarget = nSize - nMaxPos;

		while (true)
		{
			int nPos = nSize - nTarget;
			if (nPos <= 0)
			{
				for (int i = 0; i < nSize; i++)
				{
					cout << vArr[i] << ' ';
				}
				break;
			}
			else
			{
				for (int i = nPos; i < nSize; i++)
				{
					cout << vArr[i] << ' ';
				}
				nSize -= nTarget;
				if (nSize == 0)
					break;
			}
		}
		cout << '\n';
	}

	system("pause");

	return 0;
}