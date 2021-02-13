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

matrix operator * (const matrix &A, const matrix &B)
{
	ull nSize = A.size();
	matrix mTemp(nSize, vector<ull>(nSize, 0));

	for (ull i = 0; i < nSize; i++)
	{
		for (ull j = 0; j < nSize; j++)
		{
			ull nSum = 0;
			for (int x = 0; x < nSize; x++)
			{
				nSum += A[i][x] * B[x][j];
			}
			mTemp[i][j] = nSum % 1000;
		}
	}
	return mTemp;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ull nSize, nCount;
	matrix m, mResult;

	cin >> nSize >> nCount;
	m = matrix(nSize, vector<ull>(nSize, 0));
	mResult = matrix(nSize, vector<ull>(nSize, 0));

	for (ull i = 0; i < nSize; i++)
	{
		for (ull j = 0; j < nSize; j++)
			cin >> m[i][j];
	}

	for (ull i = 0; i < nSize; i++)
		mResult[i][i] = 1;

	while (nCount > 0)
	{
		if (nCount % 2 == 1)
		{
			mResult = mResult * m;
		}

		m = m * m;
		nCount /= 2;
	}

	for (ull i = 0; i < nSize; i++)
	{
		for (ull j = 0; j < nSize; j++)
			cout << mResult[i][j] << ' ';
		cout << '\n';
	}

	system("pause");

	return 0;
}