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
	int nInput, nSel = 1000, nResult = 0;
	int nCoin[6] = { 500, 100, 50, 10, 5, 1 };

	//Input
	cin >> nInput;

	//Solution
	nSel -= nInput;
	for (int i = 0; i < 6; i++)
	{
		if (nSel == 0) break;
		nResult += nSel / nCoin[i];
		nSel = nSel % nCoin[i];
	}

	//Output
	cout << nResult << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}