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

typedef pair<int, int> node;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nCount;
	cin >> nCount;
	for (int i = 0; i < nCount; i++)
	{
		priority_queue<int> pq;
		queue<node> q;
		int nSize,target;
		cin >> nSize >> target;
		int nWeight;
		for (int j = 0; j < nSize; j++)
		{
			cin >> nWeight;
			pq.push(nWeight);
			q.push(make_pair(nWeight, j));
		}

		int nOutput = 1;
		while (true)
		{
			if (pq.top() == q.front().first)
			{
				if (q.front().second == target)
				{
					cout << nOutput << '\n';
					break;
				}
				else
				{
					pq.pop();
					q.pop();
					nOutput++;
				}
			}
			else
			{
				q.push(q.front());
				q.pop();
			}				
		}
	}

	system("pause");
	
	return 0;
}