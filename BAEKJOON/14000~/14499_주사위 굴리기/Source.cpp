#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

typedef unsigned long long ull;
typedef pair<ull, ull> p;
typedef vector<vector<int>> vmap;

//custum function
void DiceRoll(vector<int>& vDice, int nCommand)
{
	//동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
	vector<int> vTemp = vDice;

	if (nCommand == 1)	//동쪽
	{
		vDice[0] = vTemp[5];	//위 <- 서
		vDice[1] = vTemp[3];	//아래 <- 동
		vDice[2] = vTemp[2];	//북 그대로
		vDice[3] = vTemp[0];	//동 <- 위
		vDice[4] = vTemp[4];	//남 그대로
		vDice[5] = vTemp[1];	//서 <- 아래
	}
	else if (nCommand == 2)	//서쪽
	{
		vDice[0] = vTemp[3];	//위 <- 동
		vDice[1] = vTemp[5];	//아래 <- 서
		vDice[2] = vTemp[2];	//북 그대로
		vDice[3] = vTemp[1];	//동 <- 아래
		vDice[4] = vTemp[4];	//남 그대로
		vDice[5] = vTemp[0];	//서 <- 위
	}
	else if (nCommand == 3)	//북쪽
	{
		vDice[0] = vTemp[4];	//위 <- 남
		vDice[1] = vTemp[2];	//아래 <- 북
		vDice[2] = vTemp[0];	//북 <- 위
		vDice[3] = vTemp[3];	//동 그대로
		vDice[4] = vTemp[1];	//남 <- 아래
		vDice[5] = vTemp[5];	//서 그대로
	}
	else if (nCommand == 4)	//남쪽
	{
		vDice[0] = vTemp[2];	//위 <- 북
		vDice[1] = vTemp[4];	//아래 <- 남
		vDice[2] = vTemp[1];	//북 <- 아래
		vDice[3] = vTemp[3];	//동 그대로
		vDice[4] = vTemp[0];	//남 <- 위
		vDice[5] = vTemp[5];	//서 그대로
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	vector<int> vDice(6, 0);	//위, 아래, 북, 동, 남, 서
	vmap vMap;
	int nSizeX, nSizeY, nX, nY, nCommandSize;
	int nMoveX[4] = { 0, 0, -1, 1 };
	int nMoveY[4] = { 1, -1, 0, 0 };

	//Input
	cin >> nSizeX >> nSizeY >> nX >> nY >> nCommandSize;
	vMap = vmap(nSizeX, vector<int>(nSizeY));
	for (int i = 0; i < nSizeX; i++)
	{
		for (int j = 0; j < nSizeY; j++)
		{
			cin >> vMap[i][j];
		}
	}

	//Solution
	for (int i = 0; i < nCommandSize; i++)
	{
		int nCommand, nPosX, nPosY;

		//명령어 입력
		cin >> nCommand;

		//주사위 회전 - 단 이동할 수 없는 위치면 통과
		nPosX = nX + nMoveX[nCommand - 1];
		nPosY = nY + nMoveY[nCommand - 1];

		//이동할 수 없으면 통과
		if(nPosX < 0 || nPosX >= nSizeX || nPosY < 0 || nPosY >= nSizeY)
			continue;

		//회전
		DiceRoll(vDice, nCommand);


		//아래 숫자 변경
		if (vMap[nPosX][nPosY] == 0)
			vMap[nPosX][nPosY] = vDice[1];
		else
		{
			vDice[1] = vMap[nPosX][nPosY];
			vMap[nPosX][nPosY] = 0;
		}

		//위치값 이동
		nX = nPosX;
		nY = nPosY;

		//값 출력
		cout << vDice[0] << '\n';
	}


	////////////////////////////////////
	system("pause");
	return 0;
}