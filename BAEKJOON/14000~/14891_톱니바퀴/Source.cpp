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
typedef pair<int, int> p;
typedef vector<vector<int>> vmap;

//custum function
void TurnGear(vector<deque<int>>& vGear, vector<bool>& vUsed, int nGear, int nDir)
{
	//이미 회전한 기어는 통과
	if (vUsed[nGear]) return;
	vUsed[nGear] = true;

	//2와 6이 맞아야함
	if(nGear != 0)
		if (vGear[nGear - 1][2] != vGear[nGear][6])
			TurnGear(vGear, vUsed, nGear - 1, -nDir);

	if (nGear != 3)
		if (vGear[nGear][2] != vGear[nGear + 1][6])
			TurnGear(vGear, vUsed, nGear + 1, -nDir);

	if (nDir == 1)
	{
		vGear[nGear].push_front(vGear[nGear].back());
		vGear[nGear].pop_back();
	}
	else
	{
		vGear[nGear].push_back(vGear[nGear].front());
		vGear[nGear].pop_front();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	vector<deque<int>> vGear(4);
	int nCmdSize, nResult = 0, nCount = 1;
	vector<p> vCmd;

	//Input
	for (int i = 0; i < 4; i++)
	{
		string strTemp;
		cin >> strTemp;
		for (int j = 0; j < 8; j++)
		{
			vGear[i].push_back(strTemp[j] - '0');
		}
	}
	cin >> nCmdSize;
	vCmd = vector<p>(nCmdSize);
	for (int i = 0; i < nCmdSize; i++)
		cin >> vCmd[i].first >> vCmd[i].second;

	//Solution
	for (int i = 0; i < nCmdSize; i++)
	{
		vector<bool> vUsed(4, false);

		TurnGear(vGear, vUsed, vCmd[i].first - 1, vCmd[i].second);
	}

	for (int i = 0; i < 4; i++)
	{
		if (vGear[i][0] == 1)
			nResult += nCount;
		nCount *= 2;
	}

	//Output
	cout << nResult << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}