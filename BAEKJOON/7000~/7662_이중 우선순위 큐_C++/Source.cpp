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
class doublePQ
{
public:
	doublePQ()
	{
		arr = vector<int>();
	}

	void input(int num)
	{
		arr.push_back(num);
		compare(arr.size() - 1);
	}

	int max()
	{
		if (arr.size() == 0)
			return -1;
		return arr[0];
	}

	int min()
	{
		if (arr.size() == 0)
			return -1;
		return arr.back();
	}

	int max_output()
	{
		if (arr.size() == 0)
			return -1;

		int num = arr[0];
		arr.erase(arr.begin());
		return num;
	}

	int min_output()
	{
		if (arr.size() == 0)
			return -1;

		int num = arr.back();
		arr.pop_back();
		return num;
	}

	int size()
	{
		return arr.size();
	}

private:
	vector<int> arr;

	void compare(int pos)
	{
		if (pos == 0)
			return;

		int up_pos = upPos(pos);

		if (arr[up_pos] < arr[pos])
		{
			int temp = arr[up_pos];
			arr[up_pos] = arr[pos];
			arr[pos] = temp;
			compare(up_pos);
		}
		sort(pos);
	}

	int upPos(int pos)
	{
		++pos;
		int size = 0;
		while (pos > 1)
		{
			pos /= 2;
			++size;
		}

		return int(pow(2, size)) - 2;
	}

	void sort(int pos)
	{
		int up_pos = upPos(pos) + 1;

		while (up_pos < pos)
		{
			if (arr[pos - 1] < arr[pos])
			{
				int temp = arr[pos - 1];
				arr[pos - 1] = arr[pos];
				arr[pos] = temp;
			}
			--pos;
		}
	}


};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int test_size(0);
	cin >> test_size;

	for (int test(0); test < test_size; ++test)
	{
		doublePQ dpq;

		int input_size(0);
		cin >> input_size;
		for (int i(0); i < input_size; ++i)
		{
			string cmd(""), num("");
			cin >> cmd >> num;
			
			if (cmd == "I")
			{
				int int_num = stoi(num);
				dpq.input(int_num);
			}
			else if (cmd == "D")
			{
				if (num == "1")
				{
					dpq.max_output();
				}
				else if (num == "-1")
				{
					dpq.min_output();
				}
			}
		}

		if (dpq.size() != 0)
		{
			cout << dpq.max() << ' ' << dpq.min() << '\n';
		}
		else
		{
			cout << "EMPTY\n";
		}
	}
	////////////////////////////////////
	system("pause");
	return 0;
}