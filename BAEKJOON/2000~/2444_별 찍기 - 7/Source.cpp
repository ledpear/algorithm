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
	int nInput, nSize;

	//Input
	cin >> nInput;

	//Solution
	//Output
	nSize = nInput * 2;
	for (int i = 1; i < nSize; i++)
	{
		int nTemp;
		string strTemp = "";

		if (i > nInput)
			nTemp = nSize - i;
		else
			nTemp = i;

		for (int j = 0; j < nInput - nTemp; j++)
			strTemp += ' ';

		for (int j = 0; j < nTemp * 2 - 1; j++)
			strTemp += '*';

		cout << strTemp << '\n';
	}

	////////////////////////////////////
	system("pause");
	return 0;
}