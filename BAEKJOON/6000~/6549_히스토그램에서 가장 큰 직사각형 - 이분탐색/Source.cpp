#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
typedef long long ll;
vector<ll> vArr;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		ll nSize;
		cin >> nSize;
		if (nSize == 0)
			break;

		ll nMax = 0;
		vArr = vector<ll>(nSize);
		for (ll i = 0; i < nSize; i++)
		{
			cin >> vArr[i];
		}

		for (ll i = 0; i < nSize; i++)
		{
			ll pos = i - 1;
			ll val = vArr[i];
			ll sum = vArr[i];

			while (pos >= 0)
			{
				if (vArr[pos] >= val)
					sum += val;
				else
					break;
				pos--;
			}
			pos = i + 1;
			while (pos < nSize)
			{
				if (vArr[pos] >= val)
					sum += val;
				else
					break;
				pos++;
			}
			if (nMax <= sum)
				nMax = sum;
		}

		cout << nMax << '\n';
	}

	system("pause");

	return 0;
}