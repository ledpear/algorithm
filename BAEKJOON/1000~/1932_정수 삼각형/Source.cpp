#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	vector<vector<int>> vDP(501, vector<int>(501, -1));
	int input;
	cin >> input;
	
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> vDP[i][j];
		}
	}

	int nMax = vDP[0][0];

	for (int i = 1; i < input; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				vDP[i][j] += vDP[i - 1][j];
			else if (i == j)
				vDP[i][j] += vDP[i - 1][j - 1];
			else
				vDP[i][j] += vDP[i - 1][j - 1] > vDP[i - 1][j] ? vDP[i - 1][j - 1] : vDP[i - 1][j];

			if (nMax < vDP[i][j] && i == input - 1)	nMax = vDP[i][j];
		}
	}

	cout << nMax << '\n';

	return 0;
}