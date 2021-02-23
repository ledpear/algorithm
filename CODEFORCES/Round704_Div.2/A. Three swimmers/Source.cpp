#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <functional>

using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> p;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nTestSize;
	cin >> nTestSize;

	for (int nTest = 0; nTest < nTestSize; nTest++)
	{
		ull n, a, b, c, nMin;
		cin >> n >> a >> b >> c;

		if (n > a)
		{
			if (n % a == 0)
				a = a * (n / a);
			else
				a = a * (n / a + 1);
		}
		if (n > b)
		{
			if (n % b == 0)
				b = b * (n / b);
			else
				b = b * (n / b + 1);
		}
		if (n > c)
		{
			if (n % c == 0)
				c = c * (n / c);
			else
				c = c * (n / c + 1);
		}

		nMin = a - n;
		if (nMin > b - n) nMin = b - n;
		if (nMin > c - n) nMin = c - n;

		cout << nMin << '\n';
	}

	system("pause");

	return 0;
}