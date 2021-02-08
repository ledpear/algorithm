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

	int nSize, nTest;
	cin >> nSize;
	vector<int> vArr(nSize);
	for (int i = 0; i < nSize; i++)
		cin >> vArr[i];

	sort(vArr.begin(), vArr.end());

	cin >> nTest;
	vector<int> vTest(nTest);
	for (int i = 0; i < nTest; i++)
		cin >> vTest[i];

	int nFirst, nLast, nFind;
	for (int i = 0; i < nTest; i++)
	{
		nFirst = 0;
		nLast = nSize - 1;
		while (true)
		{
			if (nFirst > nLast)
			{
				cout << '0';
				break;
			}
			nFind = (nFirst + nLast) / 2;
			if (vArr[nFind] == vTest[i])
			{
				cout << '1';
				break;
			}
			else
			{
				if (vArr[nFind] < vTest[i])
					nFirst = nFind + 1;
				else
					nLast = nFind - 1;
			}
		}
		cout << ' ';
	}
	cout << '\n';
	system("pause");

	return 0;
}