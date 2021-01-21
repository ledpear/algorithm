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
	vector<int> vDP(nVal);
	for (int i = 0; i < nVal; i++)
		cin >> vArr[i];

	for (int i = 0; i < nVal; i++)
	{
		vDP[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (vArr[j] < vArr[i])
				vDP[i] = max(vDP[i], vDP[j] + 1);
		}
	}

	int nMax = 0;
	for (int i = 0; i < nVal; i++)
	{
		if (nMax < vDP[i])
			nMax = vDP[i];
	}

	cout << nMax << '\n';

	return 0;
}