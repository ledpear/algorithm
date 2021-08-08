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

using namespace std;

//define

using ull = unsigned long long ;
using location =  pair<int, int> ;
using point = pair<int, int>;
using matrix = vector<vector<int>>;

//custum function
class Solution
{
private:
	int pointSize;
	int totalX, totalY;
	double minVal;
	vector<point> pointArr;

	void backTracking(int count, int sumX, int sumY, int lastIndex = -1)
	{
		if (count == pointSize / 2)
		{
			int minusX = totalX - sumX;
			int minusY = totalY - sumY;

			minVal = min(minVal, sqrt(pow(sumX - minusX, 2) + pow(sumY - minusY, 2)));
		}

		for (int index(lastIndex + 1); index < pointSize; ++index)
		{
			backTracking(count + 1, sumX + pointArr[index].first, sumY + pointArr[index].second, index);
		}
	}

	void init()
	{
		pointSize = 0;
		totalX = 0;
		totalY = 0;
		minVal = 1e9;
		pointArr.clear();
	}

	void input()
	{
		init();

		cin >> pointSize;
		pointArr = vector<point>(pointSize);

		for (int index(0); index < pointSize; ++index)
		{
			cin >> pointArr[index].first >> pointArr[index].second;
			totalX += pointArr[index].first;
			totalY += pointArr[index].second;
		}
	}

public:
	Solution()
	{
		init();
	}

	double solution()
	{
		input();
		backTracking(0, 0, 0);

		return minVal;
	}
};


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int testCase(0);
	cin >> testCase;

	//Solution
	Solution sol;
	cout<<fixed;
	cout.precision(12);
	for (int test(0); test < testCase; ++test)
	{
		cout << sol.solution() << '\n';
	}

	//Output


	////////////////////////////////////
	system("pause");
	return 0;
}