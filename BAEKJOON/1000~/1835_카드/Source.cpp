#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nInput;
	cin >> nInput;

	int nPattern = 0;
	deque<int> dq;
	int nTemp;
	for (int i = nInput; i > 0; i--)
	{
		dq.push_front(i);
		if(dq.size() == 1)
			continue;

		for (int j = 0; j < i; j++)
		{
			dq.push_front(dq.back());
			dq.pop_back();
		}
	}

	while (true)
	{
		cout << dq.front();
		dq.pop_front();
		if (dq.empty())
		{
			cout << '\n';
			break;
		}
		else
			cout << ' ';
	}

	system("pause");

	return 0;
}