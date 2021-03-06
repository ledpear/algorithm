#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

typedef unsigned long long ull;
typedef pair<ull, ull> p;
typedef vector<vector<int>> vmap;

//custum function
struct DijkstraCompare
{
	bool operator()(p a, p b)	//Node, W
	{
		return a.second > b.second;
	}
};

vector<int> Dijkstra(int nNodeSize, int nEdgeSize, int nTarget, vector<vector<p>> vEgde)
{
	vector<int> vResult(nNodeSize + 1, DEF_MAX);
	priority_queue<p, vector<p>, DijkstraCompare> pq; //(nNode, nW)

	pq.push(p(nTarget, 0));
	vResult[nTarget] = 0;

	while (!pq.empty())
	{
		int nNowNode, nNowCost;
		nNowNode = pq.top().first;
		nNowCost = pq.top().second;
		pq.pop();

		if (vResult[nNowNode] < nNowCost) continue;

		for (int i = 0; i < vEgde[nNowNode].size(); i++)
		{
			int nTargetNode, nTargetCost;
			nTargetNode = vEgde[nNowNode][i].first;
			nTargetCost = vEgde[nNowNode][i].second;

			if (vResult[nTargetNode] > nNowCost + nTargetCost)
			{
				vResult[nTargetNode] = nNowCost + nTargetCost;
				pq.push(p(nTargetNode, vResult[nTargetNode]));
			}
		}
	}

	return vResult;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int nNodeSize, nEdgeSize, nStart, nEnd;
	vector<vector<p>> vEdge;
	vector<int> vResult;

	//Input
	cin >> nNodeSize;
	cin >> nStart >> nEnd;
	cin >> nEdgeSize;
	vEdge = vector<vector<p>>(nNodeSize + 1);
	for (int i = 0; i < nEdgeSize; i++)
	{
		int nNodeA, nNodeB;
		cin >> nNodeA >> nNodeB;
		vEdge[nNodeA].push_back(p(nNodeB, 1));
		vEdge[nNodeB].push_back(p(nNodeA, 1));
	}

	//Solution
	vResult = Dijkstra(nNodeSize, nEdgeSize, nStart, vEdge);

	//Output
	if(vResult[nEnd] == DEF_MAX)
		cout << "-1\n";
	else
		cout << vResult[nEnd] << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}