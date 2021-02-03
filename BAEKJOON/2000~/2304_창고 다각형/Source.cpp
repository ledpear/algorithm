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

typedef pair<int, int> node;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<node> vArr;
	vector<int> vMap(1001,0);
	int nSize;
	cin >> nSize;
	
	for (int i = 0; i < nSize; i++)
	{
		node nTemp;
		cin >> nTemp.first >> nTemp.second;
		vMap[nTemp.first] = nTemp.second;
		vArr.push_back(nTemp);
	}

	sort(vArr.begin(), vArr.end());

	int nLeftPos = vArr[0].first;
	int nRightPos = vArr[vArr.size() - 1].first;
	int nResult = 0;
	bool bLeft = true;
	int nLeftMax = vMap[nLeftPos];
	int nRightMax = vMap[nRightPos];
	while (nLeftPos != nRightPos)
	{
		if (bLeft)
		{
			if (vMap[nLeftPos] > nLeftMax)
			{
				nLeftMax = vMap[nLeftPos];
				bLeft = !bLeft;
			}
			else
			{
				vMap[nLeftPos] = nLeftMax;
				nLeftPos++;
			}
		}
		else
		{
			if (vMap[nRightPos] > nRightMax)
			{
				nRightMax = vMap[nRightPos];
				bLeft = !bLeft;
			}
			else
			{
				vMap[nRightPos] = nRightMax;
				nRightPos--;
			}
		}
	}

	for (int i = vArr[0].first; i <= vArr[vArr.size() - 1].first; i++)
		nResult += vMap[i];

	cout << nResult << '\n';

	return 0;
}