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
	int nSum = 0, nMax = 0;

	//Input
	//Solution
	for (int i = 0; i < 4; i++)
	{
		int nInput, nOutput;
		cin >> nOutput >> nInput;
		nSum = nSum - nOutput + nInput;

		nMax = max(nMax, nSum);
	}

	//Output
	cout << nMax << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}