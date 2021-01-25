#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int gcd(int a, int b)
{
	int nBig, nSmall;
	if (a > b)
	{
		nBig = a;
		nSmall = b;
	}
	else
	{
		nBig = b;
		nSmall = a;
	}

	int nTemp;
	while (nSmall != 0)
	{
		nTemp = nBig % nSmall;
		nBig = nSmall;
		nSmall = nTemp;
	}
	return nBig;
}

int main()
{
	int nSize;
	cin >> nSize;
	vector<int> vArr(nSize);
	for (int i = 0; i < nSize; i++)
		cin >> vArr[i];

	int nGcd;
	for (int i = 1; i < nSize; i++)
	{
		nGcd = gcd(vArr[0], vArr[i]);
		cout << vArr[0] / nGcd << '/' << vArr[i] / nGcd << '\n';
	}
	system("pause");
	return 0;
}