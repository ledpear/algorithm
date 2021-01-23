#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int nSize;
	cin >> nSize;
	vector<int> nDp;
	int number;
	vector<int> vScore(nSize);
	vector<int> vArr(nSize);
	for (int i = 0; i < nSize; i++)
	{
		cin >> number;
		vArr[i] = number;
		if (nDp.size() == 0 || nDp.back() < number)
		{
			nDp.push_back(number);
			vScore[i] = nDp.size();
		}
		else
		{
			int nIndex = lower_bound(nDp.begin(), nDp.end(), number) - nDp.begin();
			nDp[nIndex] = number;
			vScore[i] = nIndex + 1;
		}
	}

	cout << nDp.size() << '\n';
	int nCount = nDp.size();
	stack<int> sOutput;
	for (int i = nSize - 1; i >= 0; i--)
	{
		if (nCount == vScore[i])
		{
			sOutput.push(vArr[i]);
			nCount--;
		}
	}
	while (!sOutput.empty())
	{
		cout << sOutput.top() << ' ';
		sOutput.pop();
	}
	cout << '\n';

	return 0;
}