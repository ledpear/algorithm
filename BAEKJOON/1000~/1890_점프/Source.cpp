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
typedef vector<vector<ull>> vmap;

//custum function

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//DFS + DP�� �ذ�
	//���ͷ� Ž���� �ϸ� ����� ���� ��ġ�� �����Ͽ� ������ �� �ִ� �޸������̼� ����� ���
	//Declaration
	int nSize, nResult;
	vmap vMap, vDP;

	//Input
	cin >> nSize;
	vMap = vmap(nSize, vector<ull>(nSize));
	vDP = vmap(nSize, vector<ull>(nSize, 0));
	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
			cin >> vMap[i][j];
	}

	//Solution
	vDP[0][0] = 1;
	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			if ((i == nSize - 1 && j == nSize - 1) || vDP[i][j] == 0) continue;

			if (i + vMap[i][j] < nSize)
				vDP[i + vMap[i][j]][j] = vDP[i + vMap[i][j]][j] + vDP[i][j];
			if (j + vMap[i][j] < nSize)
				vDP[i][j + vMap[i][j]] = vDP[i][j + vMap[i][j]] + vDP[i][j];
		}
	}

	//Output
	cout << vDP[nSize - 1][nSize - 1] << '\n';

	////////////////////////////////////
	return 0;
}