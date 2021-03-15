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
	int E, S, M, temp = 0;

	//Input
	cin >> E >> S >> M;

	//Solution
	temp = S;
	while (true)
	{
		if (E == ((temp - 1) % 15) + 1 && M == ((temp - 1) % 19) + 1)
		{
			break;
		}
		temp += 28;
	}

	//Output
	cout << temp << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}