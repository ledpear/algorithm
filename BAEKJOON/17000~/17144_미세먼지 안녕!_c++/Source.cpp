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
	//1. �̼����� Ȯ��
	//2. ����û���� �۵�

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

		//Ȯ��
		for (int x(0); x < sizeX; ++x)
		{
			for (int y(0); y < sizeY; ++y)
			{
				if (room[x][y] > 0)
				{
					//������ ������ Ȯ��Ǵ� ĭ ���� ���� ����
					tempRoom[x][y] += room[x][y];
					int diffusionVal = int(room[x][y] / 5);					

					//������ 4�������� Ȯ��ǳ�
					for (int dir(0); dir < DIRECTION; ++dir)
					{
						int posX(x + moveX[dir]), posY(y + moveY[dir]);
						//����û���Ⱑ �ְų� ĭ�� ������ Ȯ����� �ʴ´�
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
		//���� ����û����� �ݽð� �Ʒ��� �ð�
		//�ٶ��� ������ ��� �� ĭ�� �̵��ϰ�
		//����û����� �� �̼������� ��ȭ�ȴ�
		topSideWindRun();
		bottomSideWindRun();
	}

	void topSideWindRun()
	{
		//����û���� �ٷ� �� ����
		int nowX(airCleanerPos - 1), nowY(0);
		int dir(0);
		//��ȭ�Ǵ� ����
		sumVal -= room[nowX][nowY];
		//�������� ���� �̵��Ѵ�
		while (true)
		{
			int posX(nowX + topSizeMoveX[dir]), posY(nowY + topSizeMoveY[dir]);

			//���� ������ ����ٸ� ������ �ٲ۴�
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
		//����û���� �ٷ� �� ����
		int nowX(airCleanerPos + 2), nowY(0);
		int dir(0);
		//��ȭ�Ǵ� ����
		sumVal -= room[nowX][nowY];
		//�������� ���� �̵��Ѵ�
		while (true)
		{
			int posX(nowX + bottomSizeMoveX[dir]), posY(nowY + bottomSizeMoveY[dir]);

			//���� ������ ����ٸ� ������ �ٲ۴�
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