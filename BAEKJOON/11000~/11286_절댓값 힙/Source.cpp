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
typedef pair<int, bool> p;

struct compare
{
	bool operator() (p &x, p &y)
	{
		if (x.first == y.first)
		{
			if (x.second != y.second)
				return x.second;
		}

		return x > y;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nSize, nTemp;
	cin >> nSize;

	auto cmp = [&](p x, p y) 
	{ 
		if (x.first == y.first)
		{
			if (x.second != y.second)
				return x.second;
		}

		return x > y;
	};


	//priority_queue < p, vector<p>, compare > pPQ;
	priority_queue < p, vector<p>, decltype(cmp) > pPQ(cmp);

	for (int i = 0; i < nSize; i++)
	{
		cin >> nTemp;
		if (nTemp == 0)
		{
			if (pPQ.empty())
			{
				cout << "0\n";
			}
			else
			{
				if(pPQ.top().second)
					cout << pPQ.top().first << '\n';
				else
					cout << -pPQ.top().first << '\n';
				pPQ.pop();
			}
		}
		else
		{
			p pTemp;
			pTemp.first = abs(nTemp);
			pTemp.second = (nTemp > 0);
			pPQ.push(pTemp);
		}
	}

	system("pause");


	return 0;
}