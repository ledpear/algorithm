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
		vector<int> C(3, 0);
		for (int i = 0; i < nSize; i++)
		{
			cin >> vArr[i];
			C[vArr[i] % 3]++;
		}
			
		int nResult = 0;

		while(C[0] != C[1] || C[0] != C[2])
		{
			int nTemp;
			int nMax = 0;
			for (int i = 0; i < 3; i++)
			{
				if (nMax < C[i])
				{
					nMax = C[i];
					nTemp = i;
				}
			}

			if (nTemp == 0)
			{
				C[0]--;
				C[1]++;
			}
			else if (nTemp == 1)
			{
				C[1]--;
				C[2]++;
			}
			else if (nTemp == 2)
			{
				C[2]--;
				C[0]++;
			}

			nResult++;
		}
		cout << nResult << '\n';
	}
	system("pause");
	return 0;
}