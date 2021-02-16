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
vector<int> vArr;
vector<int> vResult;

void makeTree(int nStart, int nEnd, int nDepth)
{
	if (nStart == nEnd)
	{
		vResult[nStart] = nDepth;
		return;
	}
		
	int nMax = 0, pos = 0;
	for (int i = nStart; i <= nEnd; i++)
	{
		if (nMax < vArr[i])
		{
			nMax = vArr[i];
			pos = i;
		}
	}

	vResult[pos] = nDepth;
	if(nStart <= pos - 1)
		makeTree(nStart, pos - 1, nDepth + 1);
	if (pos + 1 <= nEnd)
		makeTree(pos + 1, nEnd, nDepth + 1);
}

int main()
{
	int nTestSize;
	cin >> nTestSize;
	for (int nTest = 0; nTest < nTestSize; nTest++)
	{
		int nSize;
		cin >> nSize;
		vArr = vector<int>(nSize);
		vResult = vector<int>(nSize);

		for (int i = 0; i < nSize; i++)
		{
			cin >> vArr[i];
		}

		makeTree(0, nSize - 1, 0);

		int i = 0;
		for (i; i < nSize - 1; i++)
		{
			cout << vResult[i] << ' ';
		}
		cout << vResult[i] << '\n';
	}

	system("pause");

	return 0;
}