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

typedef unsigned long long ull;
typedef vector<vector<ull>> matrix;

matrix squared(matrix m)
{
	int nSize = m.size();
	matrix mTemp = matrix(nSize, vector<ull>(nSize, 0));

	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			ull nSum = 0;
			for (int x = 0; x < nSize; x++)
			{
				nSum = (nSum + m[i][x] * m[x][j]) % 1000;
			}
			mTemp[i][j] = nSum;// % 1000;
		}
	}

	return mTemp;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nSize, nCount;
	matrix m, mResult, temp;
	bool bStart = false;

	cin >> nSize >> nCount;
	m = matrix(nSize, vector<ull>(nSize, 1));

	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
			cin >> m[i][j];
	}


	if (nCount % 2 == 1)
	{
		mResult = m;
		bStart = true;
	}

	nCount /= 2;

	while (nCount > 0)
	{
		m = squared(m);
		if (nCount % 2 == 1)
		{
			if (!bStart)
			{
				mResult = m;
				bStart = true;
				nCount /= 2;
				continue;
			}

			temp = mResult;
			for (int i = 0; i < nSize; i++)
			{
				for (int j = 0; j < nSize; j++)
				{
					ull nSum = 0;
					for (int x = 0; x < nSize; x++)
					{
						nSum = (nSum + temp[i][x] * m[x][j]) % 1000;
					}

					mResult[i][j] = nSum;// % 1000;
				}
			}
		}

		nCount /= 2;
	}

	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
			cout << mResult[i][j] << ' ';
		cout << '\n';
	}

	system("pause");

	return 0;
}