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
	//나누기 3 -> 나누기 2 -> 빼기 1 순으로 진행
	//Declaration
	int input, i = 2;
	vector<pair<int, vector<int>>> vDP;

	//Input
	cin >> input;
	vDP = vector<pair<int, vector<int>>>(input + 1, pair<int, vector<int>>(DEF_MAX, vector<int>(1, 1)));

	//Solution
	vDP[1].first = 1;
	while (i <= input)
	{
		if (i % 3 == 0)
		{
			if (vDP[i].first > vDP[i / 3].first + 1)
			{
				vector<int> temp = vDP[i / 3].second;
				temp.push_back(i);
				vDP[i] = pair<int, vector<int>>(vDP[i / 3].first + 1, temp);
			}
		}
		if (i % 2 == 0)
		{
			if (vDP[i].first > vDP[i / 2].first + 1)
			{
				vector<int> temp = vDP[i / 2].second;
				temp.push_back(i);
				vDP[i] = pair<int, vector<int>>(vDP[i / 2].first + 1, temp);
			}
		}

		if (vDP[i].first > vDP[i - 1].first + 1)
		{
			vector<int> temp = vDP[i - 1].second;
			temp.push_back(i);
			vDP[i] = pair<int, vector<int>>(vDP[i - 1].first + 1, temp);
		}

		i++;
	}

	//Output
	cout << vDP[input].first - 1 << '\n';
	for (int i = vDP[input].first - 1; 0 < i; i--)
		cout << vDP[input].second[i] << ' ';
	cout << vDP[input].second[0] << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}