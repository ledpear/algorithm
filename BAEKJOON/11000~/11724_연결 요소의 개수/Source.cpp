#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

typedef unsigned long long ull;
typedef pair<ull, ull> p;
typedef vector<vector<int>> vmap;

//custum function
bool DfsEgde(vector<int>& vVisit, const vector<vector<int>>& vEdge, int nNode)
{
	if (vVisit[nNode] == true) return false;
	vVisit[nNode] = true;

	for (int i = 0; i < vEdge[nNode].size(); i++)
	{
		DfsEgde(vVisit, vEdge, vEdge[nNode][i]);
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int nNodeSize, nEgdeSize, nCount = 0;
	vector<vector<int>> vEgde;
	vector<int> vVisit;

	//Input
	cin >> nNodeSize >> nEgdeSize;
	vEgde = vector<vector<int>>(nNodeSize);
	vVisit = vector<int>(nNodeSize, 0);
	for (int i = 0; i < nEgdeSize; i++)
	{
		int NodeA, NodeB;
		cin >> NodeA >> NodeB;
		--NodeA;
		--NodeB;
		vEgde[NodeA].push_back(NodeB);
		vEgde[NodeB].push_back(NodeA);
	}

	//Solution
	for (int i = 0; i < nNodeSize; i++)
	{
		if(vVisit[i] == true) continue;

		++nCount;
		DfsEgde(vVisit, vEgde, i);
	}

	//Output
	cout << nCount << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}