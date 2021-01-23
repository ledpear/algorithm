#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int nSize;
	cin >> nSize;
	vector<int> vArr(nSize);
	vector<int> vDp(nSize, 0);
	for (int i = 0; i < nSize; i++)
	{
		cin >> vArr[i];
	}

	int nMax = 0;
	for (int i = 0; i < nSize; i++)
	{
		vDp[i] = vArr[i];
		for (int j = 0; j < i; j++)
		{
			if (vArr[j] < vArr[i])
				vDp[i] = max(vDp[i], vDp[j] + vArr[i]);
		}
		if (nMax < vDp[i])
			nMax = vDp[i];
	}

	cout << nMax << '\n';

	system("pause");

	return 0;
}