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
	int input_size(0);

	cin >> input_size;
	vector<bool> arr = vector<bool>(21, false);

	//Solution
	for (int input(0); input < input_size; ++input)
	{
		string cmd("");
		cin >> cmd;	

		if (cmd == "add")
		{
			int val(0);
			cin >> val;
			arr[val] = true;
		}
		else if (cmd == "remove")
		{
			int val(0);
			cin >> val;
			arr[val] = false;
		}
		else if (cmd == "check")
		{
			int val(0);
			cin >> val;
			if (arr[val])
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (cmd == "toggle")
		{
			int val(0);
			cin >> val;
			arr[val] = !arr[val];
		}
		else if (cmd == "all")
		{
			arr = vector<bool>(21, true);
		}
		else if (cmd == "empty")
		{
			arr = vector<bool>(21, false);
		}
	}

	////////////////////////////////////
	system("pause");
	return 0;
}