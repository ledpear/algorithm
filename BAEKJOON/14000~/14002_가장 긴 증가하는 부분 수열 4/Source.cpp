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

	int nMax = 0;
	for (int i = 0; i < nVal; i++)
	{
		vDP[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (vArr[j] < vArr[i])
				vDP[i] = max(vDP[i], vDP[j] + 1);
		}
		if (nMax < vDP[i])
			nMax = vDP[i];
	}

	
	vector<int> vOutput;
	int nCount = nMax;
	for (int i = nVal - 1; i >= 0; i--)
	{
		if (nCount == vDP[i])
		{
			nCount--;
			vOutput.push_back(vArr[i]);
		}
	}

	cout << nMax << '\n';
	int i;
	for (i = vOutput.size() - 1; i > 0 ; i--)
		cout << vOutput[i] << ' ';
	cout << vOutput[i] << '\n';
	return 0;
}