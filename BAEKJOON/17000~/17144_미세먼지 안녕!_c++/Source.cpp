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
const int DIRECTION = 4;

//custum function
class Solution
{
	//1. 미세먼지 확산
	//2. 공기청정기 작동

private:
	const int moveX[DIRECTION] = { 1, -1, 0, 0 };
	const int moveY[DIRECTION] = { 0, 0, 1, -1 };
	const int topSizeMoveX[DIRECTION] = { -1, 0, 1, 0 };
	const int topSizeMoveY[DIRECTION] = { 0, 1, 0, -1 };
	const int bottomSizeMoveX[DIRECTION] = { 1, 0, -1, 0 };
	const int bottomSizeMoveY[DIRECTION] = { 0, 1, 0, -1 };
	int sizeX, sizeY, airCleanerPos, sumVal;
	
	matrix room;

	void init()
	{
		airCleanerPos = -1;
		room = matrix(sizeX, vector<int>(sizeY));
		sumVal = 0;
	}

	void diffusion()
	{
		matrix tempRoom(sizeX, vector<int>(sizeY));
		tempRoom[airCleanerPos][0] = -1;
		tempRoom[airCleanerPos + 1][0] = -1;

		//확산
		for (int x(0); x < sizeX; ++x)
		{
			for (int y(0); y < sizeY; ++y)
			{
				if (room[x][y] > 0)
				{
					//기존값 복사후 확산되는 칸 마다 값을 뺀다
					tempRoom[x][y] += room[x][y];
					int diffusionVal = int(room[x][y] / 5);					

					//인접한 4방향으로 확산되나
					for (int dir(0); dir < DIRECTION; ++dir)
					{
						int posX(x + moveX[dir]), posY(y + moveY[dir]);
						//공기청정기가 있거나 칸이 없으면 확산되지 않는다
						if (posX >= 0 && posX < sizeX && posY >= 0 && posY < sizeY && room[posX][posY] != -1)
						{
							tempRoom[posX][posY] += diffusionVal;
							tempRoom[x][y] -= diffusionVal;
						}
					}
				}
			}
		}

		room = tempRoom;
	}

	void airCleanerRun()
	{
		//위쪽 공기청정기는 반시계 아래는 시계
		//바람의 방향대로 모두 한 칸씩 이동하고
		//공기청정기로 들어간 미세먼지는 정화된다
		topSideWindRun();
		bottomSideWindRun();
	}

	void topSideWindRun()
	{
		//공기청정기 바로 위 부터
		int nowX(airCleanerPos - 1), nowY(0);
		int dir(0);
		//정화되는 먼지
		sumVal -= room[nowX][nowY];
		//역순으로 값을 이동한다
		while (true)
		{
			int posX(nowX + topSizeMoveX[dir]), posY(nowY + topSizeMoveY[dir]);

			//만약 범위에 벗어난다면 방향을 바꾼다
			if (posX < 0 || posY < 0 || posX > airCleanerPos || posY >= sizeY)
			{
				++dir;
				continue;
			}

			if (room[posX][posY] == -1)
			{
				room[nowX][nowY] = 0;
				break;
			}

			room[nowX][nowY] = room[posX][posY];
			nowX = posX;
			nowY = posY;
		}
	}

	void bottomSideWindRun()
	{
		//공기청정기 바로 위 부터
		int nowX(airCleanerPos + 2), nowY(0);
		int dir(0);
		//정화되는 먼지
		sumVal -= room[nowX][nowY];
		//역순으로 값을 이동한다
		while (true)
		{
			int posX(nowX + bottomSizeMoveX[dir]), posY(nowY + bottomSizeMoveY[dir]);

			//만약 범위에 벗어난다면 방향을 바꾼다
			if (posX <= airCleanerPos || posY < 0 || posX >= sizeX || posY >= sizeY)
			{
				++dir;
				continue;
			}

			if (room[posX][posY] == -1)
			{
				room[nowX][nowY] = 0;
				break;
			}

			room[nowX][nowY] = room[posX][posY];
			nowX = posX;
			nowY = posY;
		}
	}

public:
	Solution(int sizeX, int sizeY)
	{
		this->sizeX = sizeX;
		this->sizeY = sizeY;
		init();
	}

	void roomInput()
	{
		for (int x(0); x < sizeX; ++x)
		{
			for (int y(0); y < sizeY; ++y)
			{
				cin >> room[x][y];
				if (room[x][y] == -1 && airCleanerPos == -1)
				{
					airCleanerPos = x;
				}
				else if (room[x][y] > 0)
				{
					sumVal += room[x][y];
				}
			}
		}
	}

	int solution(int runTime)
	{
		for (int time(0); time < runTime; ++time)
		{
			diffusion();
			airCleanerRun();
		}

		return sumVal;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int sizeX(0), sizeY(0), time(0), airCleanerPos(-1);
	cin >> sizeX >> sizeY >> time;
	
	//Solution
	Solution sol(sizeX, sizeY);
	sol.roomInput();

	//Output
	cout << sol.solution(time) << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}