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
		int nSize, nTemp, nSum = 0, nMin, nPos;
		cin >> nSize;
		vector<int> vArr(nSize);


		for (int i = 0; i < nSize; i++)
		{
			cin >> vArr[i];
		}

		while (vArr.size() != 1)
		{
			nMin = 987654321;

			for (int i = 0; i < vArr.size() - 1; i++)
			{
				if (nMin > vArr[i] + vArr[i + 1])
				{
					nMin = vArr[i] + vArr[i + 1];
					nPos = i;
				}
			}

			vArr[nPos] = nMin;
			nSum += nMin;
			vArr.erase(vArr.begin() + nPos + 1);
		}

		cout << nSum << '\n';
	}

	system("pause");

	return 0;
}