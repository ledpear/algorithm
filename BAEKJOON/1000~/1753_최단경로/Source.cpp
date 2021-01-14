#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
#include <queue>

using namespace std;

#define INF		987654321

int main()
{
	int V, E;
	cin >> V >> E;

	vector<int> vWeight(V + 1, INF);
	int StartNode;
	cin >> StartNode;

	vector<vector<pair<int, int>>> vEdge(V + 1);

	int inputEdge;
	for (int i = 0; i < E; i++)
	{
		cin >> inputEdge;
		pair<int, int> pTemp;
		cin >> pTemp.first >> pTemp.second;
		vEdge[inputEdge].push_back(pTemp);
	}

	// 시작점으로 사용하지 않은 노드 중 최소 노드를 찾는다.
	// 해당 노드가 갈 수 있는 간선을 찾아 가중치와 값을 더 해서 현재값과 비교해 더 작은 값을 넣는다

	pair<int, int> FindNode;
	priority_queue<pair<int,int>> pq;
	pq.push(pair<int, int>(0, StartNode));

	while(pq.size() != 0)
	{
		FindNode = pq.top();
		pq.pop();
		int Node = FindNode.second;
		int Dist = -FindNode.first;

		if (Dist <= vWeight[Node])
		{
			vWeight[Node] = Dist;

			for (int j = 0; j < vEdge[Node].size(); j++)
			{
				int Cost = vWeight[Node] + vEdge[Node][j].second;
				if (Cost < vWeight[vEdge[Node][j].first])
				{
					pq.push(pair<int, int>(-Cost, vEdge[Node][j].first));
					vWeight[vEdge[Node][j].first] = Cost;
				}
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (vWeight[i] == INF)
			cout << "INF\n";
		else
			cout << vWeight[i] << "\n";
	}

	system("pause");

	return 0;
}