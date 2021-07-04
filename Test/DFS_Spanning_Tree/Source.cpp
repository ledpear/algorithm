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

const int MAX_V = 1000;
const int TREE = 1;
const int FORWARD = 2;
const int BACKWARD = 3;
const int CROSS = 4;
const string TYPE[5] = { "NONE", "tree", "forword", "backward", "cross" };

int findCnt = 0;
vector<int> adj[MAX_V], type[MAX_V];
vector<int> discovered(MAX_V, 0);
vector<int> finished(MAX_V, false);

//custum function
void DFS(int curr)
{
	discovered[curr] = ++findCnt;

	for (auto &next : adj[curr])
	{
		if (!discovered[next])
		{
			DFS(next);
			type[curr][next] = TREE;
		}
		else
		{
			if (discovered[curr] < discovered[next])
			{
				type[curr][next] = FORWARD;
			}
			else
			{
				if (finished[next])
				{
					type[curr][next] = CROSS;
				}
				else
				{
					type[curr][next] = BACKWARD;
				}
			}
		}
	}
	finished[curr] = true;

	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int v, e;

	//Solution
	cin >> v >> e;

	for (int i = 0; i < v; i++)
	{
		type[i].resize(MAX_V, 0);
	}

	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int i = 0; i < v; i++)
	{
		if (!discovered[i])
		{
			DFS(i);
		}
	}

	//Output
	for (int a = 0; a < v; a++)
	{
		for (auto &b : adj[a])
		{
			cout << "(" << a << ", " << b << ") : " << TYPE[type[a][b]] << '\n';
		}
	}

	////////////////////////////////////
	system("pause");
	return 0;
}