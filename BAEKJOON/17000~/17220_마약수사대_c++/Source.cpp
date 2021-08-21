#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int nodeSize(0), edgeSize(0), answer(0);
	cin >> nodeSize >> edgeSize;
	vector<vector<int>> edges(nodeSize, vector<int>());
	vector<int> routes(nodeSize);

	for (int idx(0); idx < edgeSize; ++idx)
	{
		char startNode(0), endNode(0);
		cin >> startNode >> endNode;
		startNode -= 'A';
		endNode -= 'A';
		edges[startNode].push_back(endNode);
		++routes[endNode];
	}

	int cutNodeSize(0);
	cin >> cutNodeSize;
	queue<int> bfsQueue;

	for (int idx(0); idx < cutNodeSize; ++idx)
	{
		char cutNode(0);
		cin >> cutNode;
		cutNode -= 'A';
		bfsQueue.push(cutNode);
		routes[cutNode] = 0;
	}

	while (!bfsQueue.empty())
	{
		int nowNode = bfsQueue.front();
		bfsQueue.pop();

		for (auto nextNode : edges[nowNode])
		{
			--routes[nextNode];
			if (routes[nextNode] == 0)
			{
				bfsQueue.push(nextNode);
			}
		}
	}

	for (int idx(0); idx < nodeSize; ++idx)
	{
		if (routes[idx])
		{
			++answer;
		}
	}

	cout << answer << '\n';
	return 0;
}