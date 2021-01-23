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
	vector<int> vDp(nSize);
	for (int i = 0; i < nSize; i++)
	{
		cin >> vArr[i];
	}

	int nMax = vArr[0];

	vDp[0] = vArr[0];

	for (int i = 1; i < nSize; i++)
	{
		vDp[i] = max(vArr[i], vArr[i] + vDp[i - 1]);
		if (nMax < vDp[i])
			nMax = vDp[i];
	}

	cout << nMax << '\n';

	system("pause");

	return 0;
}