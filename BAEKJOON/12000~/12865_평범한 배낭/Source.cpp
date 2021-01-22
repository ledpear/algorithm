#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int nVal, nSize;
	cin >> nVal >> nSize;
	vector<vector<int>> vArr(nVal, vector<int>(2));
	vector<vector<int>> vDp(nVal, vector<int>(nSize + 1, 0));

	for (int i = 0; i < nVal; i++)
	{
		cin >> vArr[i][0] >> vArr[i][1];
	}

	int nMax = 0;
	for (int i = 0; i < nVal; i++)
	{
		int nWeight = vArr[i][0];
		int nValue = vArr[i][1];

		for (int j = 1; j <= nSize; j++)
		{
			if (i != 0)
			{
				if (nWeight <= j)
					vDp[i][j] = max(vDp[i - 1][j], nValue + vDp[i - 1][j - nWeight]);
				else
					vDp[i][j] = vDp[i - 1][j];
			}
			else
			{
				if (nWeight <= j)
					vDp[i][j] = nValue;
				else
					vDp[i][j] = 0;
			}
		}
	}

	cout << vDp[nVal - 1][nSize] << '\n';

	system("pause");

	return 0;
}