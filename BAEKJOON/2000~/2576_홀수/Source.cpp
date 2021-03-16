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
	int nSum = 0, nMin = DEF_MAX;

	//Input
	//Solution
	for (int i = 0; i < 7; i++)
	{
		int nTemp;
		cin >> nTemp;
		if (nTemp % 2 == 1)
		{
			nSum += nTemp;
			nMin = min(nMin, nTemp);
		}
	}

	//Output
	if (nSum == 0)
		cout << "-1\n";
	else
	{
		cout << nSum << '\n';
		cout << nMin << '\n';
	}

	////////////////////////////////////
	system("pause");
	return 0;
}