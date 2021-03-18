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
	int nMax(DEF_MIN), nWinner(0);
	//Solution
	for (int nPeople = 0; nPeople < 5; ++nPeople)
	{
		int nSum(0);
		for (int nScoreCount = 0; nScoreCount < 4; ++nScoreCount)
		{
			int nScore(0);
			cin >> nScore;
			nSum += nScore;
		}
		if (nMax < nSum)
		{
			nMax = nSum;
			nWinner = nPeople + 1;
		}
	}

	//Output
	cout << nWinner << ' ' << nMax << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}