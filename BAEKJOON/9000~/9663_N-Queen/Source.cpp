#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void BackTracking(int &Score, vector<int> vMap, int N, int nRow)
{
	if (N == nRow)
	{
		Score++;
		return;
	}
	else
	{
		for (int nCol = 0; nCol < N; nCol++)
		{
			bool bPass = true;
			for (int backRow = 0; backRow < nRow; backRow++)
			{
				int backCol = vMap[backRow];
				if (backCol == nCol || (nRow - backRow) == abs(nCol - backCol))
				{
					bPass = false;
					break;
				}
			}
			if (bPass)
			{
				vector<int> vTemp = vMap;
				vTemp[nRow] = nCol;
				BackTracking(Score, vTemp, N, nRow + 1);
			}
		}
	}
}

int main()
{
	int input;
	cin >> input;

	vector<int> vMap(input, -1);
	int Score = 0;
	int nRow = 0;
	BackTracking(Score, vMap, input, nRow);

	cout << Score << endl;

	return 0;
}