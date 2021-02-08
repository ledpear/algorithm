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

vector<int> vArr;

bool Search(int nTarget)
{
	int nFirst = 0;
	int nLast = vArr.size() - 1;
	int nFind;
	while (nFirst <= nLast)
	{
		nFind = (nFirst + nLast) / 2;

		if (vArr[nFind] == nTarget)
			return true;
		else
		{
			if (vArr[nFind] < nTarget)
				nFirst = nFind + 1;
			else
				nLast = nFind - 1;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nSize, nTest;
	cin >> nSize;
	vArr = vector<int>(nSize);
	for (int i = 0; i < nSize; i++)
		cin >> vArr[i];

	sort(vArr.begin(), vArr.end());

	cin >> nTest;
	vector<int> vTest(nTest);
	for (int i = 0; i < nTest; i++)
		cin >> vTest[i];

	for (int i = 0; i < nTest; i++)
		cout << Search(vTest[i]) << '\n';

	system("pause");

	return 0;
}