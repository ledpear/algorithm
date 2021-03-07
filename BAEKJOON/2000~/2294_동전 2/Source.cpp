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

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

typedef unsigned long long ull;
typedef pair<ull, ull> p;
typedef vector<vector<int>> vmap;

//custum function
template <typename T>
void tSwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////

	int nCoinSize, nTarget;
	cin >> nCoinSize >> nTarget;
	vector<int> vCoin(nCoinSize);
	vector<int> vDP(nTarget + 1, DEF_MAX);
	for (int i = 0; i < nCoinSize; i++)
		cin >> vCoin[i];

	for (int i = 0; i <= nTarget; i++)
	{
		for (int j = 0; j < nCoinSize; j++)
		{
			if (i - vCoin[j] > 0)
			{
				if (vDP[i - vCoin[j]] != DEF_MAX)
				{
					vDP[i] = min(vDP[i - vCoin[j]] + vDP[vCoin[j]], vDP[i]);
				}
			}
			if (i - vCoin[j] == 0)
			{
				vDP[i] = 1;
			}
		}
	}

	if(vDP[nTarget] == DEF_MAX)
		cout << "-1\n";
	else
		cout << vDP[nTarget] << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}