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
	vector<int> vArr(nVal);
	for (int i = 0; i < nVal; i++)
		cin >> vArr[i];
	vector<int> vUpDp(nVal), vDownDp(nVal), vDp(nVal);
	

	for (int i = 0; i < nVal; i++)
	{
		vUpDp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (vArr[j] < vArr[i])
				vUpDp[i] = max(vUpDp[i], vUpDp[j] + 1);
		}
	}

	for (int i = nVal - 1; i >= 0; i--)
	{
		vDownDp[i] = 1;
		for (int j = nVal - 1; j > i; j--)
		{
			if (vArr[j] < vArr[i])
				vDownDp[i] = max(vDownDp[i], vDownDp[j] + 1);
		}
	}

	int nMax = 0;
	for (int i = 0; i < nVal; i++)
	{
		vDp[i] = vUpDp[i] + vDownDp[i] - 1;
		if (nMax < vDp[i])
			nMax = vDp[i];
	}

	cout << nMax << '\n';

	return 0;
}