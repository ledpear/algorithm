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
	//Output
	for (int i = 0; i < nInput; i++)
	{
		string strTemp = "";

		int temp = (nInput - i) * 2 - 1;

		for (int j = 0; j < i; j++)
			strTemp += ' ';

		for (int j = 0; j < temp; j++)
			strTemp += '*';

		cout << strTemp << '\n';
	}


	////////////////////////////////////
	system("pause");
	return 0;
}