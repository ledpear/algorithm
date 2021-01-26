#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int nSize, nCount;
	cin >> nSize >> nCount;

	vector<vector<int>> vDP(nSize + 1, vector<int>(nSize + 1));

	for (int i = 0; i <= nSize; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				vDP[i][j] = 1;
			else
				vDP[i][j] = (vDP[i - 1][j - 1] + vDP[i - 1][j]) % 10007;
		}
	}

	cout << vDP[nSize][nCount] << '\n';

	system("pause");

	return 0;
}