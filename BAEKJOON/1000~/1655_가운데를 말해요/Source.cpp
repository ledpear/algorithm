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
#include <functional>

using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> p;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int nSize, nTemp, nMid;
	cin >> nSize;
	priority_queue<int, vector<int>, greater<int>> pq_Min;
	priority_queue<int> pq_Max;
	
	for (int i = 0; i < nSize; i++)
	{
		cin >> nTemp;

		if (pq_Min.size() == pq_Max.size())
			pq_Max.push(nTemp);
		else
			pq_Min.push(nTemp);

		if (!pq_Max.empty() && !pq_Min.empty())
		{
			if (pq_Max.top() > pq_Min.top())
			{
				nTemp = pq_Max.top();
				pq_Max.pop();
				pq_Max.push(pq_Min.top());
				pq_Min.pop();
				pq_Min.push(nTemp);
			}
		}

		cout << pq_Max.top() << '\n';
	}


	system("pause");
	return 0;
}