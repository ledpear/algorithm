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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nNodes, nEdges;
	cin >> nNodes;
	cin >> nEdges;
	vector<vector<bool>> vMap(nNodes + 1, vector<bool>(nNodes + 1, false));

	int nStartNode, nEndNode;
	for (int i = 0; i < nEdges; i++)
	{
		cin >> nStartNode >> nEndNode;
		vMap[nStartNode][nEndNode] = true;
		vMap[nEndNode][nStartNode] = true;
	}

	stack<int> s;
	vector<bool> vVisit(nNodes + 1, false);
	s.push(1);

	int nNode, nCount = 0;
	while (!s.empty())
	{
		nNode = s.top();
		s.pop();
		if (!vVisit[nNode])
		{
			vVisit[nNode] = true;

			if(nNode != 1)
				nCount++;

			for (int i = 1; i <= nNodes; i++)
			{
				if (vMap[nNode][i])
					s.push(i);
			}
		}
	}

	cout << nCount << '\n';

	return 0;
}