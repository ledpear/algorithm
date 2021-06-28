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
	int target(0), errorbutton_size(0);
	vector<bool> vButton = vector<bool>(10, true);
	cin >> target;
	cin >> errorbutton_size;
	for (int index(0); index < errorbutton_size; ++index)
	{
		int errorbutton(0);
		cin >> errorbutton;
		vButton[errorbutton] = false;
	}

	//Solution
	int minVal = abs(target - 100);

	for (int channel(0); channel <= 1000000; ++channel)
	{
		string str_channel(to_string(channel));
		int now_channel(channel);
		bool pass(false);

		for (char c : str_channel)
		{
			int button = c - '0';
			if (!vButton[button])
			{
				pass = true;
				break;
			}
		}
		
		if (pass)
		{
			continue;
		}

		int move_count = abs(channel - target) + str_channel.size();
		minVal = min(move_count, minVal);
	}

	//Output
	cout << minVal << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}