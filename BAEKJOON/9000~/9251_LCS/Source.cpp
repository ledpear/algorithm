#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	string strA, strB;
	cin >> strA >> strB;

	vector<vector<int>> vDp(strA.size() + 1, vector<int>(strB.size() + 1, 0));
	int nMax = 0;
	for (int i = 1; i <= strA.size(); i++)
	{
		for (int j = 1; j <= strB.size(); j++)
		{
			if (strA[i - 1] == strB[j - 1])
				vDp[i][j] = vDp[i - 1][j - 1] + 1;
			else
				vDp[i][j] = max(vDp[i - 1][j], vDp[i][j - 1]);
		}
	}

	cout << vDp[strA.size()][strB.size()] << '\n';

	system("pause");

	return 0;
}