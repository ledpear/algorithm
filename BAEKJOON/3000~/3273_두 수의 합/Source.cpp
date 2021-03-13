#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

typedef unsigned long long ull;
typedef pair<ull, ull> p;
typedef vector<vector<int>> vmap;

//custum function

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int nSize, nTarget, nResult = 0, nFront, nBack;
	vector<int> vArr;

	//Input
	cin >> nSize;
	vArr = vector<int>(nSize);
	for (int i = 0; i < nSize; i++)
		cin >> vArr[i];
	cin >> nTarget;

	//Solution
	nFront = 0;
	nBack = nSize - 1;
	sort(vArr.begin(), vArr.end());

	while (nFront != nBack)
	{
		if (vArr[nFront] + vArr[nBack] == nTarget)
		{
			nResult++;
			nFront++;
		}
		else if (vArr[nFront] + vArr[nBack] < nTarget)
		{
			nFront++;
		}
		else if (vArr[nFront] + vArr[nBack] > nTarget)
		{
			nBack--;
		}
	}

	//Output
	cout << nResult << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}