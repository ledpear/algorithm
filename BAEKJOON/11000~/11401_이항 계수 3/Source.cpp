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

#define MOD 1000000007LL;
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ull N, K;
	cin >> N >> K;

	ull nN = 1, nK = 1;

	for (int i = 2; i <= N; i++)
	{
		nN = (nN * i) % MOD;
	}

	for (int i = 2; i <= K; i++)
	{
		nK = (nK * i) % MOD;
	}

	for (int i = 2; i <= N - K; i++)
	{
		nK = (nK * i) % MOD;
	}

	ull nTemp = MOD;
	nTemp -= 2;
	ull nK_Temp = nK;
	ull nK_Result = 1;
	while (nTemp != 0)
	{
		if (nTemp % 2 == 1)
			nK_Result = (nK_Result * nK_Temp) % MOD;

		nK_Temp = (nK_Temp * nK_Temp) % MOD;
		nTemp /= 2;
	}

	ull Result = (nN * nK_Result) % MOD;

	cout << Result << '\n';

	system("pause");

	return 0;
}