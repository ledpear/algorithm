#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int gcd(int nBig, int nSmall)
{
	int temp;
	if (nSmall > nBig)
	{
		int temp = nSmall;
		nSmall = nBig;
		nBig = temp;
	}
	while (nSmall != 0)
	{
		temp = nBig % nSmall;
		nBig = nSmall;
		nSmall = temp;
	}
	return nBig;
}

int main()
{
	int nCount;
	cin >> nCount;
	for (int i = 0; i < nCount; i++)
	{
		int nSmall, nBig;
		cin >> nSmall >> nBig;
		cout << nBig * nSmall / gcd(nBig, nSmall) << '\n';
	}

	system("pause");
	return 0;
}