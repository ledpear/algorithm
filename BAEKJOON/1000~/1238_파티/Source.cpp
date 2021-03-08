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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//���ͽ�Ʈ�� �˰����� ���
	//�� �л����� ��ǥ ���÷� �̵��ϴ� �ð���
	//��ǥ���ÿ��� �� �л��� �ִ� ������ ���� �ð��� ���� ������
	//���ͽ�Ʈ�� �˰������� �л����� ���̴� ������ �ҿ�ð�(����ġ)�� ����Ͽ�
	//�ִ��� ��ȯ
	//Declaration
	int nNodeSize, nEdgeSize, nTarget, nResult = 0;
	vector<vector<p>> vEgde;	// vEgde[Start Node] -> pair(End Node, Time)
	vector<int> vResult;

	//Input
	cin >> nNodeSize >> nEdgeSize >> nTarget;
	vEgde = vector<vector<p>>(nNodeSize + 1);
	for (int i = 0; i < nEdgeSize; i++)
	{
		int nStartNode, nEndNode, nW;
		cin >> nStartNode >> nEndNode >> nW;
		vEgde[nStartNode].push_back(p(nEndNode, nW));
	}

	//Solution
	for (int i = 1; i <= nNodeSize; i++)
	{
		if(i == nTarget) continue;

		int Cost = 0;
		Cost += Dijkstra(nNodeSize, nEdgeSize, i, vEgde)[nTarget];	//go
		Cost += Dijkstra(nNodeSize, nEdgeSize, nTarget, vEgde)[i];	//back
		if (nResult < Cost)
			nResult = Cost;
	}

	//Output
	cout << nResult << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}