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
typedef unsigned long long ull;
vector<int> vArr;
int nResult = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nSize, nTarget;
	cin >> nSize >> nTarget;
	vArr = vector<int>(nSize);
	for (int i = 0; i < nSize; i++)
		cin >> vArr[i];
	sort(vArr.begin(), vArr.end());

	ull start, end, find, Result;
	start = 1;
	end = vArr[nSize - 1];
	Result = 0;

	while (start <= end)
	{
		find = (start + end) / 2;
		int nCount = 1;
		int pos = 0;
		for (int i = 1; i < nSize; i++)
		{
			if (find <= vArr[i] - vArr[pos])
			{
				nCount++;
				pos = i;
			}
		}
		if (nTarget <= nCount)
		{
			start = find + 1;
			Result = max(Result, find);
		}
		else
		{
			end = find - 1;
		}
	}

	cout << Result << '\n';
	system("pause");

	return 0;
}