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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int nSize, nTarget, nResult = 0;
	set<int> sArr;
	vector<int> vArr;

	//Input
	cin >> nSize;
	for (int i = 0; i < nSize; i++)
	{
		int nTemp;
		cin >> nTemp;
		vArr.push_back(nTemp);
		if (sArr.find(nTemp) == sArr.end())
			sArr.insert(nTemp);
	}
	cin >> nTarget;

	//Solution
	for (int i = 0; i < nSize; i++)
	{
		if (sArr.find(nTarget - vArr[i]) != sArr.end())
			nResult++;
	}

	//Output
	cout << nResult / 2 << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}