#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int nSize;
	cin >> nSize;
	vector<int> vArr(nSize);
	for (int i = 0; i < nSize; i++)
		cin >> vArr[i];

	sort(vArr.begin(), vArr.end());
	int n = vArr[1] - vArr[0];
	for (int i = 2; i < nSize; i++)
	{
		n = gcd(n, vArr[i] - vArr[i - 1]);
	}

	vector<int> vResult;

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			vResult.push_back(i);
			if (n / i != i)
				vResult.push_back(n / i);
		}
	}
	vResult.push_back(n);
	sort(vResult.begin(), vResult.end());

	int i;
	for (i = 0; i < vResult.size() - 1; i++)
		cout << vResult[i] << ' ';
	cout << vResult[i] << '\n';

	system("pause");

	return 0;
}