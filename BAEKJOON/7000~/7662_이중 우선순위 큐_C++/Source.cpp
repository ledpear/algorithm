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

using ull = unsigned long long;
using location = pair<int, int>;
using matrix = vector<vector<int>>;

//custum function
struct node
{
	int val;
	int id;
	node(int input_val, int input_id) : val(input_val), id(input_id) {};
};

struct compareMax
{
	bool operator()(node a, node b)
	{
		return a.val < b.val;
	}
};
struct compareMin
{
	bool operator()(node a, node b)
	{
		return a.val > b.val;
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
		priority_queue<node, vector<node>, compareMax> max_q;
		priority_queue<node, vector<node>, compareMin> min_q;
		int input_size(0);
		cin >> input_size;
		vector<bool> visit = vector<bool>(input_size, false);

		for (int i(0); i < input_size; ++i)
		{
			string cmd(""), num("");
			cin >> cmd >> num;

			if (cmd == "I")
			{
				int int_num = stoi(num);

				max_q.push(node(int_num, i));
				min_q.push(node(int_num, i));
			}
			else if (cmd == "D")
			{
				if (num == "1")
				{
					if (max_q.empty())
						continue;

					while (!max_q.empty())
					{
						if (visit[max_q.top().id])
						{
							max_q.pop();
						}
						else
						{
							break;
						}
					}

					if (max_q.empty())
						continue;

					visit[max_q.top().id] = true;
					max_q.pop();
				}
				else if (num == "-1")
				{
					if (min_q.empty())
						continue;

					while (!min_q.empty())
					{
						if (visit[min_q.top().id])
						{
							min_q.pop();
						}
						else
						{
							break;
						}
					}

					if (min_q.empty())
						continue;

					visit[min_q.top().id] = true;
					min_q.pop();
				}
			}
		}

		while (!max_q.empty())
		{
			if (visit[max_q.top().id])
			{
				max_q.pop();
			}
			else
			{
				break;
			}
		}
		while (!min_q.empty())
		{
			if (visit[min_q.top().id])
			{
				min_q.pop();
			}
			else
			{
				break;
			}
		}

		if (!max_q.empty() && !min_q.empty())
		{
			cout << max_q.top().val << ' ' << min_q.top().val << '\n';
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