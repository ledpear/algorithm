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
	int nInput;

	//Input
	cin >> nInput;

	//Solution
	for (int i = 1; i <= nInput; i++)
	{
		string strTemp = "";
		for (int j = 0; j < nInput - i; j++)
			strTemp += ' ';

		for (int j = 0; j < i * 2 - 1; j++)
		{
			if (j % 2 == 0)
				strTemp += '*';
			else
				strTemp += ' ';
		}

		cout << strTemp << '\n';
	}

	//Output


	////////////////////////////////////
	system("pause");
	return 0;
}