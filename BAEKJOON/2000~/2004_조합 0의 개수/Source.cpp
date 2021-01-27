#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
#define max 1000000000000
typedef pair<unsigned long long, int> node;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<unsigned long long>> vDP(n + 1, vector<unsigned long long>(n + 1));
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			unsigned long long temp;
			if (j == 0 || j == i)
			{
				vDP[i][j] = 1;
			}
			else
			{
				vDP[i][j] = (vDP[i - 1][j - 1] + vDP[i - 1][j]) % max;
			}

			if (i == n && j == m) break;
		}
	}

	int nCount = 0;

	while (true)
	{
		if (vDP[n][m] % 10 == 0)
		{
			nCount++;
			vDP[n][m] /= 10;
		}
		else
		{
			break;
		}
	}

	cout << nCount << '\n';

	system("pause");

	return 0;
}