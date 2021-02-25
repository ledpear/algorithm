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
typedef unsigned long long ull;
typedef pair<ull, ull> p;
typedef vector<vector<int>> vmap;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nStart, nTarget, nFind = 0;
	cin >> nStart >> nTarget;
	queue<int> q;
	bool bVisit[100001] = { 0, };
	q.push(nStart);
	while (!q.empty())
	{
		queue<int> qTemp = queue<int>();

		while (!q.empty())
		{
			int pos = q.front();
			q.pop();

			if (pos == nTarget)
			{
				q = queue<int>();
				qTemp = queue<int>();
				break;
			}

			bVisit[pos] = true;
			if (pos < 100000 && !bVisit[pos + 1])
				qTemp.push(pos + 1);
			if (pos > 0 && !bVisit[pos - 1])
				qTemp.push(pos - 1);
			if (pos * 2 <= 100000 && !bVisit[pos * 2])
				qTemp.push(pos * 2);
		}
		
		q = qTemp;
		nFind++;
	}

	cout << nFind - 1 << '\n';
	system("pause");

	return 0;
}