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

	int nSize, nCount;
	cin >> nSize >> nCount;
	queue<int> q;

	for (int i = 1; i <= nSize; i++)
	{
		q.push(i);
	}

	int pos = 1;
	cout << '<';
	while (q.size() > 1)
	{
		if (pos == nCount)
		{
			cout << q.front() << ", ";
			q.pop();
			pos = 1;
		}
		else
		{
			q.push(q.front());
			q.pop();
			pos++;
		}
	}
	cout << q.front() << ">";
	system("pause");

	return 0;
}