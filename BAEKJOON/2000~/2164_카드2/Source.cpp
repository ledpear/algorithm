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
	{
		q.push(i);
	}

	while (q.size() != 1)
	{
		q.pop();
		int nTemp = q.front();
		q.pop();
		q.push(nTemp);
	}

	cout << q.back() << '\n';

	system("pause");

	return 0;
}