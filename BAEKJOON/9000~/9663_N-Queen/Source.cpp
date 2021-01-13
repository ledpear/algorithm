#include <vector>
#include <iostream>

using namespace std;

void BackTracking(int &Score, vector<vector<int>> vMap, int N, int count)
{
	if (N == count)
	{
		Score++;
		return;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if(vMap[i][j])	continue;
				else
				{
					vector<vector<int>> vTemp = vMap;

					vTemp[i][j] = true;
					for (int a = 0; a < N; a++)
					{
						vTemp[i][a] = true;
						vTemp[a][j] = true;
						if (i - a >= 0)
						{
							if (j - a >= 0)
								vTemp[i - a][j - a] = true;
							if (j + a < N)
								vTemp[i - a][j + a] = true;
						}
						if (i + a < N)
						{
							if (j - a >= 0)
								vTemp[i + a][j - a] = true;
							if (j + a < N)
								vTemp[i + a][j + a] = true;
						}
					}

					BackTracking(Score, vTemp, N, count + 1);
				}
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
	int count = 0;
	BackTracking(Score, vMap, input, count);

	return 0;
}