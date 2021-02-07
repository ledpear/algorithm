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

void QT(int h, int w, int size)
{
// 	if (size == 1)
// 	{
// 		nResult[vMap[h][w]]++;
// 		return vMap[h][w];
// 	}		
	
	int nSize = size / 3;
	int nVal = vMap[h][w];
	bool bResult = true;

	for (int i = h; i < h + size; i++)
	{
		for (int j = w; j < w + size; j++)
		{
			bResult = (nVal == vMap[i][j]);
			if (!bResult) break;
		}
		if (!bResult) break;
	}

	if (bResult)
	{
		nResult[nVal]++;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				QT(h + (i * nSize), w + (j * nSize), nSize);
			}
		}
	}
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