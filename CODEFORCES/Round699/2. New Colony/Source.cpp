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

	int TestSize;
	cin >> TestSize;
	for (int nTest = 0; nTest < TestSize; nTest++)
	{
		int nSize, nCount, nResult;
		cin >> nSize >> nCount;
		vector<int> vArr(nSize);
		for (int i = 0; i < nSize; i++)
			cin >> vArr[i];

		for (int i = 0; i < nCount; i++)
		{
			nResult = -1;
			for (int j = 0; j < nSize - 1; j++)
			{
				if (vArr[j] < vArr[j + 1])
				{
					vArr[j]++;
					nResult = j + 1;						
					break;
				}
			}
			if (nResult == -1)
				break;
		}

		cout << nResult << '\n';
	}

	system("pause");

	return 0;
}