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
//template <typename T>
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

vmap FloydWarshall(const vmap vMap)
{
	int nNodeSize = vMap.size();
	vmap vResult = vMap;

	for (int i = 0; i < nNodeSize; i++)
	{
		for (int j = 0; j < nNodeSize; j++)
		{
			for (int k = 0; k < nNodeSize; k++)
			{
				if (k != i && k != j && i != j && vResult[i][k] != DEF_MAX && vResult[k][j] != DEF_MAX)
				{
					if (vResult[i][j] > vResult[i][k] + vResult[k][j])
					{
						vResult[i][j] = vResult[i][k] + vResult[k][j];
					}
				}
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
	//다익스트라 알고리즘을 사용
	//각 학생들이 목표 도시로 이동하는 시간과
	//목표도시에서 각 학생이 있는 곳으로 가는 시간이 같기 때문에
	//다익스트라 알고리즘으로 학생들이 모이는 도시의 소요시간(가중치)를 계산하여
	//최댓값을 반환
	//Declaration
	int nNodeSize, nEdgeSize, nTarget, nResult = 0;
	vector<vector<p>> vEgde;	// vEgde[Start Node] -> pair(End Node, Time)
	vector<int> vResult;

	vmap vMap;

	//Input
	cin >> nNodeSize >> nEdgeSize >> nTarget;
	//vEgde = vector<vector<p>>(nNodeSize + 1);
	vMap = vmap(nNodeSize, vector<int>(nNodeSize, DEF_MAX));
	for (int i = 0; i < nEdgeSize; i++)
	{
		int nStartNode, nEndNode, nW;
		cin >> nStartNode >> nEndNode >> nW;
		//vEgde[nStartNode].push_back(p(nEndNode, nW));
		vMap[nStartNode - 1][nEndNode - 1] = nW;
	}
	for (int i = 0; i < nNodeSize; i++)
		vMap[i][i] = 0;

	//Solution
// 	for (int i = 1; i <= nNodeSize; i++)
// 	{
// 		if(i == nTarget) continue;
// 
// 		int Cost = 0;
// 		Cost += Dijkstra(nNodeSize, nEdgeSize, i, vEgde)[nTarget];	//go
// 		Cost += Dijkstra(nNodeSize, nEdgeSize, nTarget, vEgde)[i];	//back
// 		if (nResult < Cost)
// 			nResult = Cost;
// 	}

	vMap = FloydWarshall(vMap);
	for (int i = 0; i < nNodeSize; i++)
	{
		nResult = max(nResult, vMap[i][nTarget - 1] + vMap[nTarget - 1][i]);
	}

	//Output
	cout << nResult << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}