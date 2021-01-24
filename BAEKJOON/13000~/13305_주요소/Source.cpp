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
	vector<int> vDist(nSize - 1);
	vector<int> vCity(nSize);
	for (int i = 0; i < nSize - 1; i++)
		cin >> vDist[i];
	for (int i = 0; i < nSize; i++)
		cin >> vCity[i];

	long long nCost = 0;
	long long nPrice = 1000000001;
	for (int i = 0; i < nSize - 1; i++)
	{
		if (nPrice > vCity[i])
			nPrice = vCity[i];
		nCost += nPrice * vDist[i];
	}

	cout << nCost << '\n';

	system("pause");

	return 0;
}