#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int nVal;
	cin >> nVal;

	vector<int> vArr(501, 0);
	vector<int> vDp(501, 0);
	int nMin = 501;
	int nMax = 0;

	int nStart, nEnd;
	for (int i = 0; i < nVal; i++)
	{
		cin >> nStart >> nEnd;
		vArr[nStart] = nEnd;
		if (nStart < nMin)
			nMin = nStart;
		if (nStart > nMax)
			nMax = nStart;
	}

	for (int i = nMin; i <= nMax; i++)
	{
		if (vArr[i] != 0)
		{
			vDp[i] = 1;
			for (int j = nMin; j < i; j++)
			{
				if (vArr[j] != 0)
				{
					if (vArr[j] < vArr[i])
						vDp[i] = max(vDp[i], vDp[j] + 1);
				}
			}
		}
	}

	int nResult = 0;
	for (int i = nMin; i <= nMax; i++)
	{
		if (vDp[i] > nResult)
			nResult = vDp[i];
	}

	cout << nVal - nResult << '\n';

	system("pause");

	return 0;
}