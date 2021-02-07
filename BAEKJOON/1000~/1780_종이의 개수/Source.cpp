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

vector<vector<int>> vMap;
int nResult[3] = { 0, };

int QT(int h, int w, int size)
{
	if (size == 1)
	{
		nResult[vMap[h][w]]++;
		return vMap[h][w];
	}		
	
	int nSize = size / 3;
	int nVal = vMap[h][w];
	bool bResult = true;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			bResult = (nVal == QT(h + (i * nSize), w + (j * nSize), nSize));
		}
	}

	if (bResult)
	{
		nResult[nVal] -= 8;
		return nVal;
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
	
	vMap = vector<vector<int>>(nSize, vector<int>(nSize));
	int nTemp;
	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			cin >> nTemp;
			vMap[i][j] = nTemp + 1;
		}			
	}

	QT(0, 0, nSize);

	for (int i = 0; i < 3; i++)
		cout << nResult[i] << '\n';

	system("pause");

	return 0;
}