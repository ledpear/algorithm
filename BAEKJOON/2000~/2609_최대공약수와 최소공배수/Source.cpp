#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int nSmall, nBig;
	cin >> nSmall >> nBig;

	if (nSmall > nBig)
	{
		int temp = nBig;
		nBig = nSmall;
		nSmall = temp;
	}

	int nDiv, nMul;

	for (int i = 1; i <= nSmall; i++)
	{
		if (nSmall % i == 0 && nBig % i == 0)
			nDiv = i;
	}

	int SmallTemp = nSmall;
	int BigTemp = nBig;
	while (SmallTemp != BigTemp)
	{
		if (SmallTemp < BigTemp)
			SmallTemp += nSmall;
		else
			BigTemp += nBig;
	}
	cout << nDiv << '\n';
	cout << SmallTemp << '\n';

	system("pause");

	return 0;
}