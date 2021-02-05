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

		vector<vector<pair<int,int>>> vEdge(nNodeSize + 1);
		vector<vector<int>> vMap(nNodeSize + 1, vector<int>(nNodeSize + 1, INF));

		int nStartNode;
		int nRoute[2];
		cin >> nStartNode >> nRoute[0] >> nRoute[1];

		for (int i = 0; i < nEdgeSize; i++)
		{
			int nStart, nEnd, nW;
			cin >> nStart >> nEnd >> nW;
			vEdge[nStart].emplace_back(nEnd, nW);
			vEdge[nEnd].emplace_back(nStart, nW);
		}

		priority_queue<pair<int, int>> pq;
		pq.push(make_pair(0, nStartNode));
		vMap[nStartNode][nStartNode] = 0;

		while (!pq.empty())
		{
			pair<int, int> nTemp = pq.top();
			pq.pop();

			int nCost = -nTemp.first;
			int nNode = nTemp.second;

			for (int i = 0; i < vEdge[nNode].size(); i++)
			{
				int nTempNode = vEdge[nNode][i].first;
				int nTempCost = vEdge[nNode][i].second;

				if (vMap[nStartNode][nTempNode] > nCost + nTempCost)
				{
					vMap[nStartNode][nTempNode] = nCost + nTempCost;
					pq.push(make_pair(-vMap[nStartNode][nTempNode], nTempNode));
				}					
			}
		}

		for (int i = 0; i < 2; i++)
		{
			pq.push(make_pair(0, nRoute[i]));
			vMap[nRoute[i]][nRoute[i]] = 0;

			while (!pq.empty())
			{
				pair<int, int> nTemp = pq.top();
				pq.pop();

				int nCost = -nTemp.first;
				int nNode = nTemp.second;

				for (int j = 0; j < vEdge[nNode].size(); j++)
				{
					int nTempNode = vEdge[nNode][j].first;
					int nTempCost = vEdge[nNode][j].second;

					if (vMap[nRoute[i]][nTempNode] > nCost + nTempCost)
					{
						vMap[nRoute[i]][nTempNode] = nCost + nTempCost;
						pq.push(make_pair(-vMap[nRoute[i]][nTempNode], nTempNode));
					}
				}
			}
		}

		vector<int> vResult;

		for (int i = 0; i < nTargetSize; i++)
		{
			int nTarget;
			cin >> nTarget;

			for (int j = 0; j < 2; j++)
			{
				if (vMap[nStartNode][nTarget] == vMap[nStartNode][nRoute[j]] + vMap[nRoute[0]][nRoute[1]] + vMap[nRoute[!j]][nTarget])
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