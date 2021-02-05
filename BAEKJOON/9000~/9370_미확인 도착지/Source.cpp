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
#define INF 987654321

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int TestCase;
	cin >> TestCase;

	for (int test = 0; test < TestCase; test++)
	{
		int nNodeSize, nEdgeSize, nTargetSize;
		cin >> nNodeSize >> nEdgeSize >> nTargetSize;

		vector<vector<int>> vMap(nNodeSize + 1, vector<int>(nNodeSize + 1, INF));

		for (int i = 1; i <= nNodeSize; i++)
			vMap[i][i] = 0;

		int nStartNode;
		int nRoute[2];
		cin >> nStartNode >> nRoute[0] >> nRoute[1];

		for (int i = 0; i < nEdgeSize; i++)
		{
			int nStart, nEnd, nW;
			cin >> nStart >> nEnd >> nW;
			vMap[nStart][nEnd] = nW;
			vMap[nEnd][nStart] = nW;
		}

		for (int k = 1; k <= nNodeSize; k++)
		{
			for (int i = 1; i <= nNodeSize; i++)
			{
				for (int j = 1; j <= nNodeSize; j++)
				{
					vMap[i][j] = min(vMap[i][j], vMap[i][k] + vMap[k][j]);
				}
			}
		}

		int nMin = INF;
		vector<int> vResult;
		for (int i = 0; i < nTargetSize; i++)
		{
			int nTarget;
			cin >> nTarget;

			for (int j = 0; j < 2; j++)
			{
				int nTemp = vMap[nStartNode][nRoute[j]] + vMap[nRoute[0]][nRoute[1]] + vMap[nRoute[!j]][nTarget];
				if (vMap[nStartNode][nTarget] == nTemp)
				{
					vResult.push_back(nTarget);
					break;
				}
			}
		}
		sort(vResult.begin(), vResult.end());
		for (int i = 0; i < vResult.size() - 1; i++)
			cout << vResult[i] << ' ';
		cout << vResult[vResult.size() - 1] << '\n';
	}

	system("pause");

	return 0;
}