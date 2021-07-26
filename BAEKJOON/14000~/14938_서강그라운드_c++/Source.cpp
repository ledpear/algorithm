#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//define

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;

const int INF = 1e9;

//custum function

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int areaSize(0), searchRange(0), edgeSzie(0);
	cin >> areaSize >> searchRange >> edgeSzie;

	//각 area의 아이템 갯수
	vector<int> areaItems(areaSize + 1);
	for (int index(1); index <= areaSize; ++index)
	{
		cin >> areaItems[index];
	}

	//간선입력
	matrix edges(areaSize + 1, vector<int>(areaSize + 1, INF));
	for (int index(0); index < edgeSzie; ++index)
	{
		int nodeA(0), nodeB(0), cost(0);
		cin >> nodeA >> nodeB >> cost;
		edges[nodeA][nodeB] = cost;
		edges[nodeB][nodeA] = cost;
	}

	//Solution
	//플로이드 와셜
	for (int k(1); k <= areaSize; ++k)
	{
		for (int i(1); i <= areaSize; ++i)
		{
			for (int j(1); j <= areaSize; ++j)
			{
				edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
			}
		}
	}

	//최대 아이템 개수 계산
	int maxVal(0);
	for (int index(1); index <= areaSize; ++index)
	{
		int sumVal(0);
		for (int node(1); node <= areaSize; ++node)
		{
			if (index == node || edges[index][node] <= searchRange)
			{
				sumVal += areaItems[node];
			}
		}
		maxVal = max(maxVal, sumVal);
	}

	//Output
	cout << maxVal << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}