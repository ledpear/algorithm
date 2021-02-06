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

vector<int> vArr(9);
vector<int> vResult;
vector<int> vOutput;
int nSum = 0;
bool bResult = false;

void BT(int start, int count)
{
	if (!bResult)
	{
		if (nSum > 100)
		{
			return;
		}
		else if (count == 7 && nSum == 100)
		{
			bResult = true;
			return;
		}
		else
		{
			for (int i = start; i < 9 - (6 - count); i++)
			{
				if (!bResult)
				{
					nSum += vArr[i];
					vResult.push_back(vArr[i]);
					BT(i + 1, count + 1);
				}				
				
				if (!bResult)
				{
					nSum -= vArr[i];
					vResult.pop_back();
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
		cin >> vArr[i];

	BT(0, 0);

	sort(vResult.begin(), vResult.end());
	for (int i = 0; i < 7; i++)
		cout << vResult[i] << '\n';

	system("pause");

	return 0;
}