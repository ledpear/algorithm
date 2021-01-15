#include <vector>
#include <iostream>
#include <utility>

using namespace std;

vector<vector<int>> gMap;
bool bResult;

void BackTracking(vector<vector<int>> vMap, vector<vector<int>> vRow, vector<vector<int>> vColumn, vector<vector<int>> vArea,
	vector<pair<int, int>> vFind, int nCnt)
{
	if (vFind.size() != nCnt)
	{
		pair<int, int> pTemp = vFind[nCnt];

		int nX = pTemp.second;
		int nY = pTemp.first;

		for (int a = 1; a <= 9; a++)
		{
			if (vRow[nY][a] == false && vColumn[nX][a] == false && vArea[(((nY - 1) / 3) * 3) + (((nX - 1) / 3) % 3) + 1][a] == false)
			{
				vMap[nY][nX] = a;
				vRow[nY][a] = true;
				vColumn[nX][a] = true;
				vArea[(((nY - 1) / 3) * 3) + (((nX - 1) / 3) % 3) + 1][a] = true;
				BackTracking(vMap, vRow, vColumn, vArea, vFind, nCnt + 1);
				vMap[nY][nX] = 0;
				vRow[nY][a] = false;
				vColumn[nX][a] = false;
				vArea[(((nY - 1) / 3) * 3) + (((nX - 1) / 3) % 3) + 1][a] = false;
			}
		}
	}
	else
	{
		gMap = vMap;

		for (int i = 1; i < 10; i++)
		{
			int j;
			for (j = 1; j < 9; j++)
			{
				cout << gMap[i][j] << " ";
			}
			cout << gMap[i][j] << "\n";
		}

		system("pause");
		exit(0);
	}
}

int main()
{
	vector<vector<int>> vMap(10, vector<int>(10, 0));
	vector<vector<int>> vRow = vMap;
	vector<vector<int>> vColumn = vMap;
	vector<vector<int>> vArea = vMap;

	vector<pair<int, int>> vFind;

	for (int i = 1; i < 10; i++)
	{
		cin >> vMap[i][1] >> vMap[i][2] >> vMap[i][3] >> vMap[i][4] >> vMap[i][5] >>
			vMap[i][6] >> vMap[i][7] >> vMap[i][8] >> vMap[i][9];

		for (int j = 1; j < 10; j++)
		{
			if (vMap[i][j] != 0)
			{
				vRow[i][vMap[i][j]] = true;
				vColumn[j][vMap[i][j]] = true;
				vArea[(((i - 1) / 3) * 3) + (((j - 1) / 3) % 3) + 1][vMap[i][j]] = true;
			}
			else
			{
				vFind.push_back(make_pair(i, j));
			}
		}
	}

	gMap = vMap;
	bResult = false;

	BackTracking(vMap, vRow, vColumn, vArea, vFind, 0);

	return 0;
}