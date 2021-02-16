#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>>

using namespace std;

set<int> sResult;
vector<int> vArr;

void bt(int nRound)
{
	int nSize = vArr.size(), nTemp;
	if (nRound == nSize - 1)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (vArr[i] != 0)
			{
				if (sResult.find(i + 1) == sResult.end())
					sResult.insert(i + 1);
				return;
			}
		}
	}

	for (int i = 0; i < nSize; i++)
	{
		if(vArr[i] == 0)
			continue;

		for (int j = 0; j < nSize; j++)
		{
			if (i != j && vArr[j] != 0)
			{
				if (vArr[i] > vArr[j])
				{
					nTemp = vArr[j];
					vArr[i] += vArr[j];
					vArr[j] = 0;
					bt(nRound + 1);
					vArr[j] = nTemp;
					vArr[i] -= nTemp;
				}
				else if (vArr[i] < vArr[j])
				{
					nTemp = vArr[i];
					vArr[j] += vArr[i];
					vArr[i] = 0;
					bt(nRound + 1);
					vArr[i] = nTemp;
					vArr[j] -= nTemp;
				}
				else
				{
					nTemp = vArr[j];
					vArr[i] += vArr[j];
					vArr[j] = 0;
					bt(nRound + 1);

					vArr[j] = vArr[i];
					vArr[i] = 0;
					bt(nRound + 1);

					vArr[i] = vArr[j] - nTemp;
					vArr[j] = nTemp;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nTestSize;
	cin >> nTestSize;
	for (int nTest = 0; nTest < nTestSize; nTest++)
	{
		int nSize;
		cin >> nSize;
		vArr = vector<int>(nSize);
		for (int i = 0; i < nSize; i++)
			cin >> vArr[i];

		sResult.clear();

		bt(0);

		cout << sResult.size() << '\n';
		for (auto iter = sResult.begin(); iter != sResult.end(); iter++)
		{
			cout << *iter << ' ';
		}
		cout << '\n';
	}

	system("pause");

	return 0;
}