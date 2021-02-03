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

typedef vector<vector<int>> cMap;

int nW;
int nB;

cMap vMap;

int sol(int nX, int nY, int nSize)
{
	if (nSize == 1)
	{
		if (vMap[nY][nX])
			nB++;
		else
			nW++;

		return vMap[nY][nX];
	}
		

	bool bCompare;
	int nHalfSize = nSize / 2;
	int LeftTop = sol(nX, nY, nHalfSize);
	int RightTop = sol(nX + nHalfSize, nY, nHalfSize);
	int LeftBottom = sol(nX, nY + nHalfSize, nHalfSize);
	int RightBottom = sol(nX + nHalfSize, nY + nHalfSize, nHalfSize);

	if (LeftTop == -1 || RightTop == -1 || LeftBottom == -1 || RightBottom == -1)
		return -1;
	
	if (LeftTop == RightTop && LeftTop == LeftBottom && LeftTop == RightBottom)
	{
		if (LeftTop)
			nB -= 3;
		else
			nW -= 3;

		return LeftTop;
	}
	else
		return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nSize;
	cin >> nSize;
	vMap = cMap(nSize, vector<int>(nSize));

	nW = 0;
	nB = 0;

	for (int i = 0; i < nSize; i++)
		for (int j = 0; j < nSize; j++)
			cin >> vMap[i][j];

	sol(0, 0, nSize);

	cout << nW << '\n';
	cout << nB << '\n';

	system("pause");

	return 0;
}