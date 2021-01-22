#include <vector>
#include <iostream>
#include <utility>

using namespace std;

vector<vector<int>> vMap(10, vector<int>(10, 0));
vector<vector<int>> vRow = vMap;
vector<vector<int>> vColumn = vMap;
vector<vector<int>> vArea = vMap;
vector<pair<int, int>> vFind;
vector<vector<int>> gMap;
bool bResult;

void BackTracking(int nCnt)
{
	//한번도 모든 빈칸을 채우지 못했을 때 실행
	if (vFind.size() != nCnt && !bResult)
	{
		pair<int, int> pTemp = vFind[nCnt];

		int nX = pTemp.second;
		int nY = pTemp.first;

		for (int a = 1; a <= 9; a++)
		{
			if (vRow[nY][a] == false && vColumn[nX][a] == false && vArea[(((nY - 1) / 3) * 3) + (((nX - 1) / 3) % 3) + 1][a] == false)
			{
				//각 배열을 true 처리 후 재귀
				vMap[nY][nX] = a;
				vRow[nY][a] = true;
				vColumn[nX][a] = true;
				vArea[(((nY - 1) / 3) * 3) + (((nX - 1) / 3) % 3) + 1][a] = true;
				BackTracking(nCnt + 1);
				//반환되면 다시 배열을 false 처리
				vMap[nY][nX] = 0;
				vRow[nY][a] = false;
				vColumn[nX][a] = false;
				vArea[(((nY - 1) / 3) * 3) + (((nX - 1) / 3) % 3) + 1][a] = false;
			}
		}
	}
	else
	{
		if (!bResult)
		{
			//전역변수에 값을 넘겨주고 다른 재귀함수가 실행되지 않도록 처리
			gMap = vMap;
			bResult = true;
		}
	}
}

int main()
{
	//cin, cout 시간단축
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i < 10; i++)
	{
		//입력
		cin >> vMap[i][1] >> vMap[i][2] >> vMap[i][3] >> vMap[i][4] >> vMap[i][5] >>
			vMap[i][6] >> vMap[i][7] >> vMap[i][8] >> vMap[i][9];

		for (int j = 1; j < 10; j++)
		{
			if (vMap[i][j] != 0)
			{
				//받은 입력값을 가지고 각 배열에 적용
				vRow[i][vMap[i][j]] = true;
				vColumn[j][vMap[i][j]] = true;
				//3x3구역 계산 식
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

	//백트래킹 재귀함수 실행
	BackTracking(0);

	// 출력
	for (int i = 1; i < 10; i++)
	{
		int j;
		for (j = 1; j < 9; j++)
		{
			cout << gMap[i][j] << " ";
		}
		cout << gMap[i][j] << "\n";
	}

	return 0;
}