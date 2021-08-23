#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct starEdge
{
	double dict;
	int nodeA, nodeB;
	starEdge(double d, int A, int B) : dict(d), nodeA(A), nodeB(B) {}
	bool operator<(const starEdge s) const
	{
		return this->dict > s.dict;
	}
};

int find(vector<int>& rootArr, int findNode)
{
	if (rootArr[findNode] == findNode)
		return findNode;

	return rootArr[findNode] = find(rootArr, rootArr[findNode]);
}

bool unionNode(vector<int>& rootArr, int nodeA, int nodeB)
{
	int rootA = find(rootArr, nodeA);
	int rootB = find(rootArr, nodeB);

	if (rootA == rootB)
	{
		return false;
	}

	if (rootA < rootB)
	{
		rootArr[rootB] = rootA;
	}
	else
	{
		rootArr[rootA] = nodeB;
	}
}

double getDist(const vector<double>& nodeA, const vector<double>& nodeB)
{
	return sqrt(pow(abs(nodeA[0] - nodeB[0]), 2) + pow(abs(nodeA[1] - nodeB[1]), 2));
}

int main()
{
	int nodeSize = 0;
	cout << fixed;
	cout.precision(2);
	cin >> nodeSize;
	vector<vector<double>> nodeInfo;
	for (int idx = 0; idx < nodeSize; ++idx)
	{
		double x(0.0), y(0.0);
		cin >> x >> y;
		nodeInfo.push_back(vector<double>{ x, y });
	}

	if (nodeSize == 1)
	{
		cout << 0.00 << '\n';
		return 0;
	}

	vector<bool> visit(nodeSize);
	priority_queue<starEdge> edgeQueue;

	visit[0] = true;
	for (int idx(1); idx < nodeSize; ++idx)
	{
		double dict = getDist(nodeInfo[0], nodeInfo[idx]);
		edgeQueue.push(starEdge(dict, 0, idx));
	}

	vector<int> rootArr(nodeSize);
	for (int idx(0); idx < nodeSize; ++idx)
	{
		rootArr[idx] = idx;
	}

	int count(0);
	double answer(0.0);
	while (count < nodeSize - 1)
	{
		double dict(edgeQueue.top().dict);
		int nodeA(edgeQueue.top().nodeA), nodeB(edgeQueue.top().nodeB);
		edgeQueue.pop();

		if (unionNode(rootArr, nodeA, nodeB))
		{
			++count;
			answer += dict;
			//처음가는 노드면 경로를 추가한다
			if (!visit[nodeA])
			{
				visit[nodeA] = true;
				for (int idx(0); idx < nodeSize; ++idx)
				{
					if (!visit[idx])
					{
						double dict = getDist(nodeInfo[nodeA], nodeInfo[idx]);
						edgeQueue.push(starEdge(dict, nodeA, idx));
					}					
				}
			}

			if (!visit[nodeB])
			{
				visit[nodeB] = true;
				for (int idx(0); idx < nodeSize; ++idx)
				{
					if (!visit[idx])
					{
						double dict = getDist(nodeInfo[nodeB], nodeInfo[idx]);
						edgeQueue.push(starEdge(dict, nodeB, idx));
					}
				}
			}
		}
	}

	cout << answer << '\n';
	return 0;
}