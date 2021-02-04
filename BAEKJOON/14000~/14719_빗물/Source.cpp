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

	int nH, nW;
	cin >> nH >> nW;

	vector<int> vArr(nW);

	for (int i = 0; i < nW; i++)
		cin >> vArr[i];

	int nMax = 0;
	int nResult = 0;
	int nPos = 0;

	for (int i = 0; i < nW; i++)
	{
		if (nMax <= vArr[i])
		{
			for (int j = nPos; j < i; j++)
			{
				nResult += nMax - vArr[j];
			}
			nMax = vArr[i];
			nPos = i;
		}
	}

	nMax = 0;
	nPos = nW - 1;
	for (int i = nW - 1; i >= 0; i--)
	{
		if (nMax < vArr[i])
		{
			for (int j = nPos; j > i; j--)
			{
				nResult += nMax - vArr[j];
			}
			nMax = vArr[i];
			nPos = i;
		}
	}

	cout << nResult << '\n';

	system("pause");

	return 0;
}