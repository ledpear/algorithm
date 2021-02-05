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

typedef vector<vector<int>> cMap;
cMap vMap;
cMap vUsed;
int M, N, K;

void Worm(int x, int y)
{
	if (x < 0 || x >= M || y < 0 || y >= N)
		return;

	if (vMap[x][y] && !vUsed[x][y])
	{
		vUsed[x][y] = true;

		Worm(x + 1, y);
		Worm(x - 1, y);
		Worm(x, y + 1);
		Worm(x, y - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nTestSize;
	cin >> nTestSize;

	for (int nTest = 0; nTest < nTestSize; nTest++)
	{
		cin >> M >> N >> K;
		vMap = cMap(M, vector<int>(N, false));
		vUsed = cMap(M, vector<int>(N, false));
		vector<pair<int, int>> vBugs;
		int nBug = 0;

		int x, y;
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			vBugs.emplace_back(x, y);
			vMap[x][y] = true;
		}

		for (int i = 0; i < K; i++)
		{
			if (vUsed[vBugs[i].first][vBugs[i].second] == false)
			{
				++nBug;

				Worm(vBugs[i].first, vBugs[i].second);
			}
		}

		cout << nBug << '\n';
	}


	system("pause");

	return 0;
}