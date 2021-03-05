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
typedef unsigned long long ull;
typedef pair<ull, ull> p;
typedef vector<vector<int>> vmap;

typedef pair<p, int> edge;
#define INF 987654321
struct compare
{
	bool operator()(p a, p b)
	{
		return a.second > b.second;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nNodes, nEdges, nStart, nEnd;
	cin >> nNodes;
	cin >> nEdges;



	vector<int> vArr(nNodes + 1, INF);
	vector<bool> vVisit(nNodes + 1, false);
	vector<vector<p>> vEdge(nNodes + 1);
	priority_queue<p, vector<p>, compare> pq;

	for (int i = 0; i < nEdges; i++)
	{
		int nStartNode, nEndNode, nW;
		cin >> nStartNode >> nEndNode >> nW;
		vEdge[nStartNode].push_back(p(nEndNode, nW));
	}

	cin >> nStart >> nEnd;
	pq.push(p(nStart, 0));
	vArr[nStart] = 0;

	while (!pq.empty())
	{
		int nNowNode = pq.top().first;
		int nNowCost = pq.top().second;
		pq.pop();

		if(vArr[nNowNode] < nNowCost) continue;

		for (int i = 0; i < vEdge[nNowNode].size(); i++)
		{
			int nTargetNode = vEdge[nNowNode][i].first;
			int nCose = vEdge[nNowNode][i].second;

			if (vArr[nTargetNode] > vArr[nNowNode] + nCose)
			{
				vArr[nTargetNode] = vArr[nNowNode] + nCose;
				pq.push(p(nTargetNode, vArr[nTargetNode]));
			}
		}
	}

	cout << vArr[nEnd] << '\n';
	system("pause");

	return 0;
}