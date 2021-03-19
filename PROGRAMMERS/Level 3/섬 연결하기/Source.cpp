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
int FindTop(vector<int>& vConnect, int nNode)
{
	if (vConnect[nNode] == nNode)
	{
		return nNode;
	}
	else
	{
		return vConnect[nNode] = FindTop(vConnect, vConnect[nNode]);
	}
}

int solution(int n, vector<vector<int>> costs) {
	//엣지를 하나씩 추가해서 한번의 탐색으로 모든 섬을 탐색할수있으면 종료
	//탐색은 1만함
	int answer = 0;
	int nSum(0);

	vector<int> vConnect(n, 0);
	for (int i = 0; i < n; i++)
	{
		vConnect[i] = i;
	}

	sort(costs.begin(), costs.end(), 
		[](const vector<int>& a, const vector<int>& b)
		{
			return a[2] < b[2];
		}
	);

	for (const auto& vEdge : costs)
	{
		const int nNodeA = vEdge[0];
		const int nNodeB = vEdge[1];
		const int nCost = vEdge[2];

		const int nNodeATop = FindTop(vConnect, nNodeA);
		const int nNodeBTop = FindTop(vConnect, nNodeB);

		if (nNodeATop != nNodeBTop)
		{
			nSum += nCost;
			if (nNodeATop > nNodeBTop)
			{
				vConnect[nNodeATop] = nNodeBTop;
			}
			else
			{
				vConnect[nNodeBTop] = nNodeATop;
			}
		}
	}
	answer = nSum;

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
	cout << solution(5, vector<vector<int>>{ {0, 1, 1}, { 0,2,2 }, { 1,2,5 }, { 2,3,8 }, { 3,4,1 }}) << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}