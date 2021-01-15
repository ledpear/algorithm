#include <vector>
#include <iostream>

using namespace std;

void BackTracking(int &Score, vector<vector<int>> vMap, int N, int nRow)
{
	if (N == nRow)
	{
		Score++;
		return;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (!vMap[nRow][i])
			{
				vector<vector<int>> vTemp = vMap;
				vTemp[nRow][i] = 9;

				for (int j = 1; j < N - nRow; j++)
				{
					vTemp[nRow + j][i] = true;
					if (i - j >= 0)
						vTemp[nRow + j][i - j] = true;
					if (i + j < N)
						vTemp[nRow + j][i + j] = true;
				}

				BackTracking(Score, vTemp, N, nRow + 1);
			}
		}
	}
}

int main()
{
	int input;
	cin >> input;

	vector<vector<int>> vMap(input, vector<int>(input, 0));
	int Score = 0;
	int nRow = 0;
	BackTracking(Score, vMap, input, nRow);

	cout << Score << endl;

	return 0;
}