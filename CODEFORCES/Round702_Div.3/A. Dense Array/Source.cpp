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

	int nTestSize;
	cin >> nTestSize;
	for (int nTest = 0; nTest < nTestSize; nTest++)
	{
		int nSize;
		cin >> nSize;
		vector<int> vArr(nSize);
		for (int i = 0; i < nSize; i++)
			cin >> vArr[i];

		int pos = 0;
		int nResult = 0;
		while (pos < vArr.size() - 1)
		{
			double temp = (double)max(vArr[pos], vArr[pos + 1]) / (double)min(vArr[pos], vArr[pos + 1]);
			if (temp > 2)
			{
				if((int)temp == temp)
					vArr.insert(vArr.begin() + pos + 1, temp);
				else
					vArr.insert(vArr.begin() + pos + 1, (int)temp + 1);
				nResult++;
			}				
			else
				pos++;
		}

		cout << nResult << '\n';
	}

	return 0;
}