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
	int nLeftMax = vMap[nLeftPos];
	int nRightPos = vArr[vArr.size() - 1].first;
	int nRightMax = vMap[nRightPos];

	int nResult = 0;
	bool bLeft = true;	

	for (int i = 0; i < vArr.size(); i++)
	{
		if (nLeftMax <= vArr[i].second)
		{
			nResult += (vArr[i].first - nLeftPos) * nLeftMax;
			nLeftMax = vArr[i].second;
			nLeftPos = vArr[i].first;
		}
	}

	for (int i = vArr.size() -1 ; i >= 0; i--)
	{
		if (nRightMax < vArr[i].second)
		{
			nResult += (nRightPos - vArr[i].first) * nRightMax;
			nRightMax = vArr[i].second;
			nRightPos = vArr[i].first;
		}
	}

	nResult += nLeftMax;
	
	cout << nResult << '\n';

	return 0;
}