#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> gMap;

void BackTracking(vector<vector<int>> vMap, vector<vector<int>> vRow, vector<vector<int>> vColumn, vector<vector<int>> vArea,
	bool &bFind)
{
	bool bResult = true;
	if (!bFind)
	{
		for (int i = 1; i < 10; i++)
		{
			for (int j = 1; j < 10; j++)
			{
				if (vMap[i][j] == 0)
				{
					bResult = false;
					for (int a = 1; a < 10; a++)
					{
						if (vRow[i][a] == 0 && vColumn[j][a] == 0 &&
							vArea[(((i - 1) / 3) * 3) + (((j - 1) / 3) % 3) + 1][a] == 0)
						{
							vector<vector<int>> vTampMap = vMap;
							vector<vector<int>> vTampRow = vRow;
							vector<vector<int>> vTampColumn = vColumn;
							vector<vector<int>> vTampArea = vArea;

							vTampMap[i][j] = a;
							vTampRow[i][a] = true;
							vTampColumn[j][a] = true;
							vTampArea[(((i - 1) / 3) * 3) + (((j - 1) / 3) % 3) + 1][a] = true;

							BackTracking(vTampMap, vTampRow, vTampColumn, vTampArea, bFind);
						}
					}
				}
			}
		}

		if (bResult)
		{
			bFind = true;
			gMap = vMap;
		}
	}
}

int main()
{
	vector<vector<int>> vMap(10, vector<int>(10, 0));
	vector<vector<int>> vRow = vMap;
	vector<vector<int>> vColumn = vMap;
	vector<vector<int>> vArea = vMap;

	for (int i = 1; i < 10; i++)
	{
		cin >> vMap[i][1] >> vMap[i][2] >> vMap[i][3] >> vMap[i][4] >> vMap[i][5] >>
			vMap[i][6] >> vMap[i][7] >> vMap[i][8] >> vMap[i][9];
	}

	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (vMap[i][j] != 0)
			{
				vRow[i][vMap[i][j]] = true;
				vColumn[j][vMap[i][j]] = true;
				vArea[(((i- 1) / 3) * 3) + (((j-1)/3)% 3) + 1][vMap[i][j]] = true;
			}
		}
	}
	bool bFind = false;
	gMap = vMap;
	BackTracking(vMap, vRow, vColumn, vArea, bFind);

	if (gMap != vMap)
	{
		for (int i = 1; i < 10; i++)
		{
			int j;
			for (j = 1; j < 9; j++)
			{
				cout << gMap[i][j] << " ";
			}
			cout << gMap[i][j] << "\n";
		}
	}

	system("pause");

	return 0;
}