#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#define INF 987654321

int main()
{
	int nNode, nEdge;
	cin >> nNode;
	cin >> nEdge;

	vector<vector<int>> vMap(nNode + 1, vector<int>(nNode + 1, INF));

	for (int i = 1; i <= nNode; i++)
		vMap[i][i] = 0;

	int StartNode, EndNode, Weight;

	for (int i = 0; i < nEdge; i++)
	{
		cin >> StartNode >> EndNode >> Weight;
		if(Weight < vMap[StartNode][EndNode])
			vMap[StartNode][EndNode] = Weight;
	}

	for (int k = 1; k <= nNode; k++)
		for (int a = 1; a <= nNode; a++)
			for (int b = 1; b <= nNode; b++)
			{
				if(k != a && k != b && a != b)
					vMap[a][b] = min(vMap[a][b], vMap[a][k] + vMap[k][b]);
			}
				

	for (int i = 1; i <= nNode; i++)
	{
		int j;
		for (j = 1; j < nNode; j++)
		{
			if (vMap[i][j] == INF)
				vMap[i][j] = 0;
			cout << vMap[i][j] << ' ';
		}
		if (vMap[i][j] == INF)
			vMap[i][j] = 0;
		cout << vMap[i][j] << '\n';
	}

	system("pause");
	return 0;
}