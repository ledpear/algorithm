#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int nSize = 0;
	int nMax = 0;
	int nMin = 1000000;

	cin >> nSize;
	vector<int> vArr(nSize);

	int nTemp;
	for (int i = 0; i < nSize; i++)
	{
		cin >> nTemp;
		vArr[i] = nTemp;
	}

	sort(vArr.begin(), vArr.end());

	int nResult = 0;
	if (nSize % 2 == 0)
		nResult = vArr[nSize / 2 - 1] * vArr[nSize / 2];
	else
		nResult = vArr[nSize / 2] * vArr[nSize / 2];

	cout << nResult << '\n';

	system("pause");

	return 0;
}