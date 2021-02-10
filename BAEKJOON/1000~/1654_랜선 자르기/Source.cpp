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

	int nSize, nTarget, nMax = 0;
	cin >> nSize >> nTarget;

	vector<int> vArr(nSize);
	for (int i = 0; i < nSize; i++)
	{
		cin >> vArr[i];
		if (nMax < vArr[i])
			nMax = vArr[i];
	}
		

	unsigned long long nStart, nEnd, nFind, nResult;
	nStart = 1;
	nEnd = nMax;
	nResult = 0;
	while (nStart <= nEnd)
	{
		nFind = (nStart + nEnd) / 2;
		int nCount = 0;
		for (int i = 0; i < nSize; i++)
		{
			nCount += vArr[i] / nFind;
		}
		if (nCount >= nTarget)
		{
			nStart = nFind + 1;
			if (nResult < nFind);
				nResult = nFind;
		}
		else
		{
			nEnd = nFind - 1;
		}
	}

	cout << nResult << '\n';
	system("pause");

	return 0;
}