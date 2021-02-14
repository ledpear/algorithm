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
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		ull nSize;
		cin >> nSize;
		if (nSize == 0)
			break;

		ull nMax = 0;
		ull nMin = 1000000001;
		vector<int> vArr(nSize);
		for (int i = 0; i < nSize; i++)
		{
			cin >> vArr[i];
			if (nMax < vArr[i])
				nMax = vArr[i];
			if (nMin > vArr[i])
				nMin = vArr[i];
		}
			
		ull nStart, nEnd, nFind, nResult;
		nResult = 0;
		nStart = nMin;
		nEnd = nMax;
		nFind = 1;

		while (nStart <= nEnd)
		{
			ull nSum = 0;
			ull nTempMin = 1000000001;
			ull nCount = 0;
			ull nTemp;
			bool bContinuous = false;
			for (int i = 0; i < nSize; i++)
			{
				if (vArr[i] >= nFind)
				{
					if (nTempMin > vArr[i])
						nTempMin = vArr[i];
					nCount++;
				}
				else
				{
					nTemp = nTempMin * nCount;
					if (nSum < nTemp)
						nSum = nTemp;
					nTemp = 0;
					nTempMin = 1000000001;
					nCount = 0;
				}
			}

			nTemp = nTempMin * nCount;
			if (nSum < nTemp)
				nSum = nTemp;

			if (nResult <= nSum)
			{
				nResult = nSum;
				nStart = nFind + 1;
			}
			else
				nEnd = nFind - 1;

			nFind = (nStart + nEnd) / 2;
		}

		cout << nResult << '\n';
	}

	system("pause");

	return 0;
}