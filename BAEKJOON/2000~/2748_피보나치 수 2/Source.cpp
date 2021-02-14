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
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ull nInput;
	cin >> nInput;

	ull dp1, dp2;
	dp1 = 0;
	dp2 = 1;

	if (nInput == 0)
	{
		cout << dp1 << '\n';
	}
	else if (nInput == 1)
	{
		cout << dp2 << '\n';
	}
	else
	{
		ull nTemp;
		for (ull i = 2; i <= nInput; i++)
		{
			nTemp = dp2;
			dp2 = dp1 + dp2;
			dp1 = nTemp;
		}
		cout << dp2 << '\n';
	}
	
	system("pause");

	return 0;
}