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

using ull = unsigned long long;
using location = pair<int, int>;
using matrix = vector<vector<int>>;

struct fallInfo
{
	int left = 101, rigth = -1;
	vector<int> floor;
};

struct node
{
	int x, y;
};


const int move_x[4] = { 1, 0, 0, -1 };
const int move_y[4] = { 0, 1, -1, 0 };

int R(0), C(0);

//custum function

bool DFS(int x, int y, vector<node> &vNode, fallInfo &fallinfo, matrix &vMatrix, vector<vector<bool>> &vVisit)
{
	vVisit[x][y] = true;

	if (fallinfo.floor[y] < x)
	{
		fallinfo.floor[y] = x;

		if (fallinfo.left > y)
			fallinfo.left = y;
		if (fallinfo.rigth < y)
			fallinfo.rigth = y;
	}

	node n;
	n.x = x;
	n.y = y;
	vNode.push_back(n);

	bool result = false;

	if (x == (R - 1))
		result = true;
	
	for (int nDir(0); nDir < 4; ++nDir)
	{
		int nPosX(0), nPosY(0);
		nPosX = x + move_x[nDir];
		nPosY = y + move_y[nDir];

		//맵 내부이면서 미네랄일 경우 탐색
		if (nPosX >= 0 && nPosY >= 0 && nPosX < R && nPosY < C)
		{
			if (vMatrix[nPosX][nPosY] && !vVisit[nPosX][nPosY])
			{
				result = DFS(nPosX, nPosY, vNode, fallinfo, vMatrix, vVisit) || result;
			}
		}
	}

	return result;
}

bool DFS(int x, int y, matrix &vMatrix, vector<vector<bool>> &vVisit)
{
	vVisit[x][y] = true;

	bool result = false;

	if (x == (R - 1))
		return true;

	for (int nDir(0); nDir < 4; ++nDir)
	{
		int nPosX(0), nPosY(0);
		nPosX = x + move_x[nDir];
		nPosY = y + move_y[nDir];

		//맵 내부이면서 미네랄일 경우 탐색
		if (nPosX >= 0 && nPosY >= 0 && nPosX < R && nPosY < C)
		{
			if (vMatrix[nPosX][nPosY] && !vVisit[nPosX][nPosY])
			{
				result = DFS(nPosX, nPosY, vMatrix, vVisit) || result;
			}
		}
	}

	return result;
}

void Fall(vector<node> &vNode, fallInfo &fallinfo, matrix &vMatrix)
{
	//클러스터를 다 탐색하면서 해당 덩어리 클러스터를 다 0으로 바꾸고 새로운 배열에 이동한 덩어리를 저장하고 탐색이 끝나면 삽입
	//그 후 다시 탐색해서 아직도 낙하중인지 확인

	while (true)
	{
		//한칸씩 이동
		//전체 순환를 기본으로 만약 이동을 이미 한 위치라면 지우지 않는다.
		vector<vector<bool>> vCheck = vector<vector<bool>>(R, vector<bool>(C, false));

		for (int index(0); index < vNode.size(); ++index)
		{
			int x = vNode[index].x;
			int y = vNode[index].y;
			int posX = x + 1;

			if (posX >= R)
				continue;

			if (!vCheck[x][y])
				vMatrix[x][y] = 0;

			if (!vMatrix[posX][y])
				vMatrix[posX][y] = 1;

			vCheck[posX][y] = true;

			vNode[index].x = posX;
		}

		//낙하중인지 확인
		int left = fallinfo.left;
		int right = fallinfo.rigth;
		bool result = false;

		for (int index(left); index <= right; ++index)
		{
			++fallinfo.floor[index];
			int underPos = fallinfo.floor[index] + 1;
			if (underPos >= R)
			{
				result = true;
			}
			else if (vMatrix[underPos][index])
			{
				result = true;
			}

			if (result)
				break;
		}
		if (result)
			break;
		//dfs로 탐색
		vector<vector<bool>> vVisit = vector<vector<bool>>(R, vector<bool>(C, false));
		if (DFS(vNode[0].x, vNode[0].y, vMatrix, vVisit))
			break;
	}
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
	matrix vMatrix = matrix(R, vector<int>(C, 0));

	for (int i(0); i < R; ++i)
	{
		string temp("");
		cin >> temp;
		for (int j(0); j < temp.size(); ++j)
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
		nLine = R - nLine;
		int nRise(1), nLine_index(0);
		if (!bLeft)
		{
			nRise = -1;
			nLine_index = C - 1;
		}

		//막대 날리는 기능
		bool bCrush = false;

		for (nLine_index; 0 <= nLine_index && nLine_index < C; nLine_index += nRise)
		{
			if (vMatrix[nLine][nLine_index])
			{
				//미네랄 파과 처리 1 -> 0
				vMatrix[nLine][nLine_index] = 0;
				bCrush = true;
				break;
			}
		}

		bLeft = !bLeft;

		if (!bCrush)
			continue;

		vector<vector<bool>> vVisit = vector<vector<bool>>(R, vector<bool>(C, false));

		for (int nDir(0); nDir < 4; ++nDir)
		{
			int nPosX(0), nPosY(0);
			nPosX = nLine + move_x[nDir];
			nPosY = nLine_index + move_y[nDir];

			fallInfo fallinfo;
			fallinfo.floor = vector<int>(C, -1);

			vector<node> vNode = vector<node>();

			bool result(true);

			//외각이 아니고 미네랄이면 낙하하는 클러스터 탐색
			if (nPosX >= 0 && nPosY >= 0 && nPosX < R && nPosY < C)
			{
				if (vMatrix[nPosX][nPosY] && !vVisit[nPosX][nPosY])
				{
					result = DFS(nPosX, nPosY, vNode, fallinfo, vMatrix, vVisit);

					//낙하하는 클러스터가 있으면
					if (!result)
					{
						//낙하 처리를 하고
						Fall(vNode, fallinfo, vMatrix);
						//탐색 종료 - 낙하하는 클러스트는 하나밖에 없으므로
						break;
					}
				}
			}
		}		
	}


	//Output
	for (int i(0); i < vMatrix.size(); ++i)
	{
		string strTemp("");
		for (int j(0); j < vMatrix[0].size(); ++j)
		{
			if (vMatrix[i][j])
				strTemp += 'x';
			else
				strTemp += '.';
		}
		cout << strTemp << '\n';
	}

	////////////////////////////////////
	system("pause");
	return 0;
}