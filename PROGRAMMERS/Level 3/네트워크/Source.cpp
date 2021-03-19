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
bool DfsEgde(vector<int>& vVisit, const vector<vector<int>>& vEdge, int nNode)
{
	if (vVisit[nNode] == true)
	{
		return false;
	}
	vVisit[nNode] = true;

	for (int i = 0; i < vEdge[nNode].size(); i++)
	{
		if (i == nNode)
		{
			continue;
		}

		if (vEdge[nNode][i] == 1)
		{
			DfsEgde(vVisit, vEdge, i);
		}
	}

	return true;
}

int solution(int n, vector<vector<int>> computers) 
{
	int nCount(0);

	vector<int> vVisit(n, false);
	for (int nNode = 0; nNode < n; ++nNode)
	{
		
		if (DfsEgde(vVisit, computers, nNode) == true)
		{
			++nCount;
		}
	}

	return nCount;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration


	//Solution


	//Output
	cout << solution(3, vector<vector<int>>{ {1, 1, 0}, { 1,1,0 }, { 0,0,1 }}) << '\n';
	cout << solution(3, vector<vector<int>>{ {1, 1, 0}, { 1,1,1 }, { 0,1,1 }}) << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}