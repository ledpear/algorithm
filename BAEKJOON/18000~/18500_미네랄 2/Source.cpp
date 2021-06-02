#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//define

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;

struct fallInfo
{
	int left = 101, rigth = -1;
	vector<int> floor;
};

const int move_x[4] = { 1, 0, 0, -1 };
const int move_y[4] = { 0, 1, -1, 0 };

int R(0), C(0);

//custum function

bool DFS(int x, int y, fallInfo &fallinfo, matrix &vMatrix, vector<vector<bool>> &vVisit)
{
	if (x == (R - 1))
		return true;

	vVisit[x][y] = true;

	if (fallinfo.floor[y] < x)
	{
		fallinfo.floor[y] = x;

		if (fallinfo.left > y)
			fallinfo.left = y;
		if (fallinfo.rigth < y)
			fallinfo.rigth = y;
	}

	bool result = false;
	for (int nDir(0); nDir < 4; ++nDir)
	{
		int nPosX(0), nPosY(0);
		nPosX = x + move_x[nDir];
		nPosY = y + move_y[nDir];

		//맵 내부이면서 미네랄일 경우 탐색
		if (nPosX >= 0 && nPosY >= 0 && nPosX < R && nPosY < C && vMatrix[nPosX][nPosY] && !vVisit[nPosX][nPosY])
		{
			result = result || DFS(nPosX, nPosY, fallinfo, vMatrix, vVisit);
			if (result)
				break;
		}
	}

	return result;
}

void Fall(fallInfo &fallinfo, matrix &vMatrix)
{
	//각 가장 아래부분이 바닥 또는 다른 미네랄에 닿는지 확인
	int count = 0; // 얼만큼 내려가는지
	bool search = false;

	int left = fallinfo.left;
	int right = fallinfo.rigth;
	vector<int> Floor = fallinfo.floor;

	//얼마나 내려가야하는 탐색
	while (true)
	{
		++count;
		for (int index(left); index <= right; ++index)
		{
			//탐색되지 않은 곳은 영역 밖
			if (Floor[index] == -1)
			{
				continue;
			}

			int underPos = Floor[index] + count + 1;

			if (underPos >= R || vMatrix[underPos][index])
			{
				search = true;
			}

			if (search)
				break;
		}

		if (search)
			break;
	}

	//실제 이동
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//매트릭스에 빈칸은 0 미네랄은 1로 표현
	//처음엔 왼쪽에서 그 다음은 오른쪽 그 다음은 왼쪽 순으로 반복해서 막대 날린다
	//1. 막대가 미네랄에 부딪혀 파괴되면 
	//2. 사방에 미네랄이 있는지 확인 있다면
	//3. 해당 미네랄이 바닥이랑 붙어있는지 dfs(or bfs)로 확인[아래 좌 우 위 순서로 탐색] - 바닥에 도달하면 바로 종료
	//4. 바닥에 연결되어있지 않은 클러스터는 낙하처리
	//5. 낙하처리는 탐색시 1차원 배열에 해당 클러스터에 가장 아래 위치를 저장해서 한칸씩 내려가면서 부딪히는지 확인
	//Declaration
	
	cin >> R >> C;
	matrix vMatrix = matrix(R, vector<int>(C,0));

	for (int i(0); i < R; ++i)
	{
		string temp("");
		cin >> temp;
		for (int j(0); j < C; ++j)
		{
			if (temp[j] == 'x')
			{
				vMatrix[i][j] = 1;
			}
		}
	}

	int N(0);
	cin >> N;
	vector<int> vCmd = vector<int>(N, 0);
	for (int i(0); i < N; ++i)
	{
		int temp(0);
		cin >> temp;
		vCmd[i] = temp;
	}

	//Solution

	bool bLeft = true;	//true면 왼쪽->오른쪽 false면 오른쪽->왼쪽
	for (int nLine : vCmd)
	{
		nLine = 8 - nLine;
		int nRise(1), nLine_index(0);
		if (!bLeft)
		{
			nRise = -1;
			nLine_index = C - 1;
		}

		//막대 날리는 기능
		for (nLine_index; 0 <= nLine_index && nLine_index < C; nLine_index += nRise)
		{
			if (vMatrix[nLine][nLine_index])
			{
				//미네랄 파과 처리 1 -> 0
				vMatrix[nLine][nLine_index] = 0;
				break;
			}				
		}

		vector<vector<bool>> vVisit = vector<vector<bool>>(R, vector<bool>(C, false));

		for (int nDir(0); nDir < 4; ++nDir)
		{
			int nPosX(0), nPosY(0);
			nPosX = nLine + move_x[nDir];
			nPosY = nLine_index + move_y[nDir];

			fallInfo fallinfo;
			fallinfo.floor = vector<int>(C, -1);
			bool result(true);

			//외각이 아니고 미네랄이면 낙하하는 클러스터 탐색
			if (nPosX >= 0 && nPosY >= 0 && nPosX < R && nPosY < C && vMatrix[nPosX][nPosY] && !vVisit[nPosX][nPosY])
			{
				result = DFS(nPosX, nPosY, fallinfo, vMatrix, vVisit);

				//낙하하는 클러스터가 있으면
				if (!result)
				{
					//낙하 처리를 하고

					//탐색 종료 - 낙하하는 클러스트는 하나밖에 없으므로
					break;
				}
			}
		}

		bLeft = !bLeft;
	}


	//Output


	////////////////////////////////////
	system("pause");
	return 0;
}