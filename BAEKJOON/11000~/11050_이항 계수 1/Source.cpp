#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int nSize, nSelect;
	cin >> nSize >> nSelect;

	int nSzieCount = 1, nSelectCount = 1;

	for (int i = nSize; i > nSize - nSelect; i--)
	{
		nSzieCount *= i;
	}

	for (int i = nSelect; i > 1; i--)
	{
		nSelectCount *= i;
	}

	cout << nSzieCount / nSelectCount << '\n';

	system("pause");

	return 0;
}