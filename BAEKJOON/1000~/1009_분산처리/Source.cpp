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
	int nTestCase;
	int a, b;

	//Input
	//Solution
	//Output
	cin >> nTestCase;
	for (int i = 0; i < nTestCase; i++)
	{
		cin >> a >> b;
		int nTemp = a % 10;
		for (int j = 1; j < b; j++)
		{
			nTemp *= a;
			nTemp = nTemp % 10;
		}
		if(nTemp == 0)
			cout << "10" << '\n';
		else
			cout << nTemp << '\n';
	}

	////////////////////////////////////
	system("pause");
	return 0;
}