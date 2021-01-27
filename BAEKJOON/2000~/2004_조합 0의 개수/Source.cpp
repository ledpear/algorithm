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
	vector<vector<node>> vDP(n + 1, vector<node>(n + 1));
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			node temp;
			if (j == 0 || j == i)
			{
				temp.first = 1;
				temp.second = 0;
				vDP[i][j] = temp;
			}
			else
			{
				temp.first = vDP[i - 1][j - 1].first + vDP[i - 1][j].first;
				temp.second = vDP[i - 1][j - 1].first + vDP[i - 1][j].first;
			}
		}
	}
	return 0;
}