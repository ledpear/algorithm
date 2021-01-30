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
	queue<int> q;
	for (int i = 1; i <= nInput; i++)
		q.push(i);

	int temp;
	while (true)
	{
		cout << q.front();
		q.pop();
		if (q.empty())
		{
			cout << '\n';
			break;
		}
		else
			cout << ' ';
		temp = q.front();
		q.pop();
		q.push(temp);
	}

	system("pause");

	return 0;
}