#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;

//custum function
int BfsEgde(vector<int>& vDist, const vector<vector<int>>& vEdges, int nStart)
{
	using node = pair<int, int>;
	int nMax(0);

	queue<node> qNode;
	qNode.push(node(nStart, nMax));
	vDist[nStart] = 0;

	while (qNode.empty() == false)
	{
		const int nNowNode = qNode.front().first;
		const int nDist = qNode.front().second;
		qNode.pop();

		//최대거리 갱신
		nMax = max(nMax, nDist);

		//이동할 수 있는 곳은 이동
		for (auto& nTargetNode : vEdges[nNowNode])
		{
			if (vDist[nTargetNode] == -1)
			{
				vDist[nTargetNode] = nDist + 1;
				qNode.push(node(nTargetNode, vDist[nTargetNode]));
			}
		}
	}

	return nMax;
}

int solution(int n, vector<vector<int>> edge) 
{
	int answer = 0;

	vector<vector<int>> vEdges(n);
	for (int nIndex = 0; nIndex < edge.size(); nIndex++)
	{
		int nNodeA = edge[nIndex][0] - 1;
		int nNodeB = edge[nIndex][1] - 1;
		vEdges[nNodeA].push_back(nNodeB);
		vEdges[nNodeB].push_back(nNodeA);
	}

	vector<int> vDist(n, -1);
	int nMax = BfsEgde(vDist, vEdges, 0);
	
	for (auto& nDist : vDist)
	{
		if (nMax == nDist)
		{
			++answer;
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration


	//Solution


	//Output


	////////////////////////////////////
	system("pause");
	return 0;
}