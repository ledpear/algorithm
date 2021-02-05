#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
#define INF 987654321

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nNodeSize, nEdgeSize;
	cin >> nNodeSize >> nEdgeSize;

	vector<vector<int>> vMap(nNodeSize + 1, vector<int>(nNodeSize+1, INF));
	for (int i = 1; i <= nNodeSize; i++)
		vMap[i][i] = 0;

	for (int i = 0; i < nEdgeSize; i++)
	{
		int startNode, EndNode, W;
		cin >> startNode >> EndNode >> W;
		vMap[startNode][EndNode] = W;
		vMap[EndNode][startNode] = W;
	}

	int RouteNodeA, RouteNodeB;
	cin >> RouteNodeA >> RouteNodeB;

	for (int a = 1; a <= nNodeSize; a++)
	{
		for (int i = 1; i <= nNodeSize; i++)
		{
			for (int j = 1; j <= nNodeSize; j++)
			{
				vMap[i][j] = min(vMap[i][j], vMap[i][a] + vMap[a][j]);
			}
		}
	}

	int nRouteA, nRouteB;

	if (vMap[1][RouteNodeA] != INF && vMap[RouteNodeA][RouteNodeB] != INF && vMap[RouteNodeB][nNodeSize] != INF)
		nRouteA = vMap[1][RouteNodeA] + vMap[RouteNodeA][RouteNodeB] + vMap[RouteNodeB][nNodeSize];
	else
		nRouteA = INF;

	if (vMap[1][RouteNodeB] != INF && vMap[RouteNodeB][RouteNodeA] != INF && vMap[RouteNodeA][nNodeSize] != INF)
		nRouteB = vMap[1][RouteNodeB] + vMap[RouteNodeB][RouteNodeA] + vMap[RouteNodeA][nNodeSize];
	else
		nRouteB = INF;

	int nResult = min(nRouteA, nRouteB);

	if (nResult == INF)
		cout << "-1\n";
	else
		cout << nResult << '\n';

	system("pause");


	return 0;
}