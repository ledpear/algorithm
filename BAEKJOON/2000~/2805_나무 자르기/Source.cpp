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

	int nSize, nTarget;
	cin >> nSize >> nTarget;
	vector<int> vArr(nSize);
	for (int i = 0; i < nSize; i++)
		cin >> vArr[i];

	unsigned long long nStart, nEnd, nFind, nResult;
	nStart = 0;
	nEnd = vArr.back();
	nResult = 0;
	while (nStart <= nEnd)
	{
		unsigned long long nSum = 0;
		nFind = (nStart + nEnd) / 2;

		for (int i = 0; i < nSize; i++)
		{
			if (vArr[i] > nFind)
				nSum += (vArr[i] - nFind);
		}

		if (nSum == nTarget)
		{
			nResult = nFind;
			break;
		}
		else
		{
			if (nSum > nTarget)
			{
				nStart = nFind + 1;
				if (nResult < nFind)nResult = nFind;
			}
			else
				nEnd = nFind - 1;
		}
	}

	cout << nResult << '\n';

	return 0;
}