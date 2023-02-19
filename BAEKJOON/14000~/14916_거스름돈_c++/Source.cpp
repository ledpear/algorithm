#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::ios_base;

using ull = unsigned long long;
using location = pair<int, int>;
using matrix = vector<vector<int>>;

using namespace std;
//define
//custum function

int solution(int n)
{
	int size = n;
	if (size < 5)
		size = 5;
	vector<int> resultArr(size + 1, -1);

	resultArr[2] = 1;
	resultArr[4] = 2;
	resultArr[5] = 1;

	for (int i = 6; i <= n; ++i)
	{
		int result = INT_MAX;
		if (resultArr[i - 2] != -1)
			result = resultArr[i - 2];

		if (i >= 5 &&  resultArr[i - 5] != -1)
			result = min(resultArr[i - 5], result);

		if (result != INT_MAX)
			resultArr[i] = result + 1;
	}
	return resultArr[n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//input
	int n = 0;
	cin >> n;

	//Solution
	int result = solution(n);

	//Output
	cout << result << endl;

	////////////////////////////////////
	return 0;
}