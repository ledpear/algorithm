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
static const int INF = 10000000;

using ull = unsigned long long;
using location = pair<int, int>;
using matrix = vector<vector<int>>;

//custum function

int getParent(vector<int>& table, int node)
{
	if (node == table[node])
	{
		return node;
	}
	return table[node] = getParent(table, table[node]);
}

bool checkParent(vector<int>& table, int nodeA, int nodeB)
{
	int parentA = getParent(table, nodeA);
	int parentB = getParent(table, nodeB);

	if (parentA == parentB)
	{
		return true;
	}
	else
	{
		table[parentB] = parentA;
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int size(0), c;
	cin >> size >> c;

	vector<vector<int>> node_positions = vector<vector<int>>();
	vector<int> table = vector<int>(size, 0);

	for (int i = 0; i < size; ++i)
	{
		int x = 0, y = 0;
		cin >> x >> y;
		node_positions.push_back({ x, y });
		table[i] = i;
	}
	//Solution

	vector<vector<int>> edges = vector<vector<int>>();
	for (int i(0); i < size; ++i)
	{
		for (int j(i + 1); j < size; ++j)
		{
			int cost = int(pow(node_positions[i][0] - node_positions[j][0], 2) + pow(node_positions[i][1] - node_positions[j][1], 2));
			if (cost >= c)
			{
				edges.push_back({ cost, i, j });
			}
		}
	}

	sort(edges.begin(), edges.end(),
		[](vector<int> a, vector<int> b) {
		return a[0] < b[0];
	});

	if (edges.size() < size - 1)
	{
		cout << "-1\n";
	}
	else
	{
		int answer = 0;
		int count = 0;
		for (vector<int> edge : edges)
		{
			int cost = edge[0];
			int nodeA = edge[1];
			int nodeB = edge[2];

			if (!checkParent(table, nodeA, nodeB))
			{
				answer += cost;
				++count;
			}

			if (count == (size - 1))
				break;
		}

		//Output
		if (count == (size - 1))
		{
			cout << answer << '\n';
		}
		else
		{
			cout << "-1\n";
		}
	}


	////////////////////////////////////
	return 0;
}