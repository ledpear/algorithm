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
int nResult = 0;
void bt(int nStart, int nCount, int nMin, int nFind)
{
	if (nCount == 0)
	{
		nResult = max(nResult, nMin);
	}
	else
	{
		int nEnd = vArr.size() - nCount;
		int nTempMin = nMin;

		for (int i = nStart; i <= nEnd; i++)
		{
			if (nFind >= 1)
				nMin = min(nMin, vArr[i] - vArr[nStart - 1]);
			bt(i + 1, nCount - 1, nMin, nFind + 1);
			nMin = nTempMin;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nSize, nCount;
	cin >> nSize >> nCount;
	vArr = vector<int>(nSize);
	for (int i = 0; i < nSize; i++)
		cin >> vArr[i];
	sort(vArr.begin(), vArr.end());

	bt(0, nCount, vArr[nSize - 1], 0);

	cout << nResult << '\n';

	system("pause");

	return 0;
}