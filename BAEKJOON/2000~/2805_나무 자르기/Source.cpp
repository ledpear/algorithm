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

	int nSize, nTarget;
	cin >> nSize >> nTarget;
	vector<int> vArr(nSize);
	for (int i = 0; i < nSize; i++)
		cin >> vArr[i];

	sort(vArr.begin(), vArr.end());

	int nStart, nEnd, nFind;
	nStart = 0;
	nEnd = vArr.back();
	while (true)
	{
		int nSum = 0;
		nFind = (nStart + nEnd) / 2;

		for (int i = 0; i < nSize; i++)
		{
			if(vArr[i] > nFind)
				nSum += (vArr[i] - nFind);
		}

		if (nSum == nTarget)
		{
			cout << nFind << '\n';
			break;
		}
		else
		{
			if (nSum < nTarget)
				nEnd = nFind - 1;
			else
				nStart = nFind + 1;
		}
	}

	system("pause");

	return 0;
}