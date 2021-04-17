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
using matrix = vector<vector<int>>;

//custum function

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	vector<string> str_arr(5);

	//Solution
	for (int i = 0; i < 5; ++i)
	{
		cin >> str_arr[i];
	}

	string answer = "";
	int pos = 0;
	while (true)
	{
		int count = 0;

		for (int i = 0; i < 5; ++i)
		{
			if (pos < str_arr[i].size())
			{
				answer += str_arr[i][pos];
				++count;
			}
		}

		if (count == 0)
		{
			break;
		}
		else
		{
			++pos;
		}
	}

	//Output
	cout << answer << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}