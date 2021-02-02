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
	int nSize;
	int nFindSize;
	cin >> nSize >> nFindSize;

	deque<int> dq;
	vector<int> vFind;
	int nTemp;
	for (int i = 1; i <= nSize; i++)
		dq.push_back(i);
	for (int i = 0; i < nFindSize; i++)
	{
		cin >> nTemp;
		vFind.push_back(nTemp);
	}

	int nCount = 0;
	deque<int> left_dq = dq;
	deque<int> right_dq = dq;
	for (int i = 0; i < nFindSize; i++)
	{
		nTemp = vFind[i];

		while (true)
		{
			if (left_dq.front() == nTemp)
			{
				left_dq.pop_front();
				right_dq = left_dq;
				break;
			}
			else if (right_dq.front() == nTemp)
			{
				right_dq.pop_front();
				left_dq = right_dq;
				break;
			}
			else
			{
				nCount++;
				left_dq.push_back(left_dq.front());
				left_dq.pop_front();
				right_dq.push_front(right_dq.back());
				right_dq.pop_back();
			}
		}	
	}

	cout << nCount << '\n';

	system("pause");

	return 0;
}