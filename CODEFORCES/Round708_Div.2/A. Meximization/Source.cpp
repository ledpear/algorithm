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
#include <functional>

using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> p;

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
		vector<int> vArr, vTemp;
		vector<bool> vUsed(102, false);

		for (int i = 0; i < nSize; i++)
		{
			int nTemp;
			cin >> nTemp;
			if (vUsed[nTemp] == false)
			{
				vArr.push_back(nTemp);
				vUsed[nTemp] = true;
			}
			else
			{
				vTemp.push_back(nTemp);
			}
		}
			
		sort(vArr.begin(), vArr.end());

		for (int i = 0; i < vArr.size(); i++)
		{
			cout << vArr[i] << ' ';
		}

		for (int i = 0; i < vTemp.size(); i++)
		{
			cout << vTemp[i] << ' ';
		}
		cout << '\n';
	}

	system("pause");

	return 0;
}