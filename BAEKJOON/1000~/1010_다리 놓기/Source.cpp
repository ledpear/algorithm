#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int nCount;
	cin >> nCount;

	vector<vector<int>> vDP(30, vector<int>(30, 0));

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				vDP[i][j] = 1;
			else
				vDP[i][j] = vDP[i - 1][j - 1] + vDP[i - 1][j];
		}
	}

	int n, m;
	for (int i = 0; i < nCount; i++)
	{
		cin >> n >> m;
		cout << vDP[m][n] << '\n';
	}

	system("pause");

	return 0;
}