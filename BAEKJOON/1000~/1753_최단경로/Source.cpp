#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>

using namespace std;

#define INF		987654321

int FindMin(vector<int> vWeight, vector<bool> vVisit)
{
	int nMin = INF;
	int nNodeNum = 0;
	for (int i = 1; i < vWeight.size(); i++)
	{
		if (!vVisit[i])
		{
			if (nMin > vWeight[i])
			{
				nMin = vWeight[i];
				nNodeNum = i;
			}
		}
	}
	return nNodeNum;
}

int main()
{
	int V, E;
	cin >> V >> E;

	vector<int> vWeight(V + 1, INF);
	vector<bool> vVisit(V + 1, false);
	int StartNode;
	cin >> StartNode;

	vWeight[StartNode] = 0;

	vector<vector<pair<int, int>>> vEdge(V + 1);

	int inputEdge;
	for (int i = 0; i < E; i++)
	{
		cin >> inputEdge;
		pair<int, int> pTemp;
		cin >> pTemp.first >> pTemp.second;
		vEdge[inputEdge].push_back(pTemp);
	}

	// ���������� ������� ���� ��� �� �ּ� ��带 ã�´�.
	// �ش� ��尡 �� �� �ִ� ������ ã�� ����ġ�� ���� �� �ؼ� �������� ���� �� ���� ���� �ִ´�

	int FindNode = 0;
	for (int i = 1; i < V; i++)
	{
		FindNode = FindMin(vWeight, vVisit);
		vVisit[FindNode] = true;

		for (int j = 0; j < vEdge[FindNode].size(); j++)
		{
			if (vWeight[vEdge[FindNode][j].first] > (vWeight[FindNode] + vEdge[FindNode][j].second))
			{
				vWeight[vEdge[FindNode][j].first] = (vWeight[FindNode] + vEdge[FindNode][j].second);
			}
		}
	}

	for (int i = 1; i < V; i++)
	{
		if (vWeight[i] == INF)
			cout << "INF\n";
		else
			cout << vWeight[i] << "\n";
	}

	return 0;
}