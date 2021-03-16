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
	int nSize;
	string strResult;

	//Input
	//Solution
	cin >> nSize;
	cin >> strResult;

	for (int i = 1; i < nSize; i++)
	{
		string strTemp;
		cin >> strTemp;

		for (int j = 0; j < strResult.size(); j++)
		{
			if (strResult[j] != '?' && strResult[j] != strTemp[j])
				strResult[j] = '?';
		}
	}

	//Output
	cout << strResult << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}