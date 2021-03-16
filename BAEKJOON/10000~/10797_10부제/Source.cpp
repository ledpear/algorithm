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
	int nTarget, nCount = 0;

	//Input
	//Solution
	cin >> nTarget;
	for (int i = 0; i < 5; i++)
	{
		int nTemp;
		cin >> nTemp;
		if (nTarget == nTemp)
			nCount++;
	}

	//Output
	cout << nCount << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}