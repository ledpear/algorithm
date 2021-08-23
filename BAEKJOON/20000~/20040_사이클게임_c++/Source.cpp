#include<iostream>
#include<vector>

using namespace std;

int find(vector<int>& rootArr, int findNode)
{
	if (rootArr[findNode] == findNode)
	{
		return findNode;
	}
	else
	{
		return rootArr[findNode] = find(rootArr, rootArr[findNode]);
	}
}

int main()
{
	int nodeSize = 0, edgeSize = 0, answer = 0;
	cin >> nodeSize >> edgeSize;

	vector<int> rootArr(nodeSize);
	for (int idx = 0; idx < nodeSize; ++idx)
	{
		rootArr[idx] = idx;
	}

	for (int idx = 0; idx < edgeSize; ++idx)
	{
		int nodeA = 0, nodeB = 0;
		cin >> nodeA >> nodeB;

		if(answer != 0)
			continue;

		int rootA = find(rootArr, nodeA);
		int rootB = find(rootArr, nodeB);

		if (rootA == rootB)
		{
			answer = idx + 1;
		}

		if (rootA < rootB)
		{
			rootArr[rootB] = rootA;
		}
		else
		{
			rootArr[rootA] = rootB;
		}
	}

	cout << answer << '\n';
	return 0;
}