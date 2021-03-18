#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;

//custum function

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int nGirl(0), nBoy(0), nInternSize(0), nResult(0);
	cin >> nGirl >> nBoy >> nInternSize;

	//Solution
	nResult = min({ nGirl / 2, nBoy, (nGirl + nBoy - nInternSize) / 3 });

	//Output
	cout << nResult << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}