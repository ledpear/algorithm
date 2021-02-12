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
typedef vector<vector<int>> MATRIX;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	MATRIX m1, m2;
	int x, y;
	cin >> y >> x;
	m1 = MATRIX(y, vector<int>(x, 0));

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cin >> m1[i][j];
		}
	}

	cin >> y >> x;
	m2 = MATRIX(y, vector<int>(x, 0));

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cin >> m2[i][j];
		}
	}

	for (int i = 0; i < m1.size(); i++)
	{
		for (int j = 0; j < m2[0].size(); j++)
		{
			int nSum = 0;
			for (int a = 0; a < m2.size(); a++)
			{
				nSum += m1[i][a] * m2[a][j];
			}
			cout << nSum << ' ';
		}
		cout << '\n';
	}

	system("pause");

	return 0;
}