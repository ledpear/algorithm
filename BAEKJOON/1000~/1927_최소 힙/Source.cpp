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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nSize, nTemp;
	priority_queue<int> pq;
	cin >> nSize;
	for (int i = 0; i < nSize; i++)
	{
		cin >> nTemp;
		if (nTemp > 0)
		{
			pq.push(-nTemp);
		}
		else
		{
			if (pq.size() > 0)
			{
				cout << -pq.top() << '\n';
				pq.pop();
			}
			else
				cout << "0\n";
		}
	}

	return 0;
}