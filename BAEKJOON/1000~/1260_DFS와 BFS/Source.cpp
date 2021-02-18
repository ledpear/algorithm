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
typedef vector<vector<int>> cMap;
cMap m;

#define INF 2147483647

void DFS(int nStartNode)
{
	stack<int> s;
	int nNode, nSize;
	nSize = m.size();
	vector<bool> bVisit(nSize, 0);
	s.push(nStartNode);
	while (!s.empty())
	{
		nNode = s.top();
		s.pop();
		if(bVisit[nNode]) continue;

		bVisit[nNode] = true;
		cout << nNode << ' ';
		for (int i = nSize - 1; i >= 1; i--)
		{
			if (m[nNode][i] && !bVisit[i])
				s.push(i);
		}
	}
	cout << '\n';
}

void BFS(int nStartNode)
{
	queue<int> q;
	int nNode, nSize;
	nSize = m.size();
	vector<bool> bVisit(nSize, 0);
	q.push(nStartNode);
	while (!q.empty())
	{
		nNode = q.front();
		q.pop();
		if (bVisit[nNode]) continue;

		bVisit[nNode] = true;
		cout << nNode << ' ';
		for (int i = 1; i < nSize; i++)
		{
			if (m[nNode][i] && !bVisit[i])
				q.push(i);
		}
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nNodes, nEdges, nStart;
	cin >> nNodes >> nEdges >> nStart;

	m = cMap(nNodes + 1, vector<int>(nNodes + 1, 0));

	int nStartNode, nEndNode;
	for (int i = 0; i < nEdges; i++)
	{
		cin >> nStartNode >> nEndNode;
		m[nStartNode][nEndNode] = 1;
		m[nEndNode][nStartNode] = 1;
	}

	DFS(nStart);
	BFS(nStart);

	system("pause");

	return 0;
}