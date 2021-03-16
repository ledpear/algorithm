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
	//������ 1, ������ 2, ������ 3, ������ 4
	vector<int> vTemp = vDice;

	if (nCommand == 1)	//����
	{
		vDice[0] = vTemp[5];	//�� <- ��
		vDice[1] = vTemp[3];	//�Ʒ� <- ��
		vDice[2] = vTemp[2];	//�� �״��
		vDice[3] = vTemp[0];	//�� <- ��
		vDice[4] = vTemp[4];	//�� �״��
		vDice[5] = vTemp[1];	//�� <- �Ʒ�
	}
	else if (nCommand == 2)	//����
	{
		vDice[0] = vTemp[3];	//�� <- ��
		vDice[1] = vTemp[5];	//�Ʒ� <- ��
		vDice[2] = vTemp[2];	//�� �״��
		vDice[3] = vTemp[1];	//�� <- �Ʒ�
		vDice[4] = vTemp[4];	//�� �״��
		vDice[5] = vTemp[0];	//�� <- ��
	}
	else if (nCommand == 3)	//����
	{
		vDice[0] = vTemp[4];	//�� <- ��
		vDice[1] = vTemp[2];	//�Ʒ� <- ��
		vDice[2] = vTemp[0];	//�� <- ��
		vDice[3] = vTemp[3];	//�� �״��
		vDice[4] = vTemp[1];	//�� <- �Ʒ�
		vDice[5] = vTemp[5];	//�� �״��
	}
	else if (nCommand == 4)	//����
	{
		vDice[0] = vTemp[2];	//�� <- ��
		vDice[1] = vTemp[4];	//�Ʒ� <- ��
		vDice[2] = vTemp[1];	//�� <- �Ʒ�
		vDice[3] = vTemp[3];	//�� �״��
		vDice[4] = vTemp[0];	//�� <- ��
		vDice[5] = vTemp[5];	//�� �״��
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	vector<int> vDice(6, 0);	//��, �Ʒ�, ��, ��, ��, ��
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

		//��ɾ� �Է�
		cin >> nCommand;

		//�ֻ��� ȸ�� - �� �̵��� �� ���� ��ġ�� ���
		nPosX = nX + nMoveX[nCommand - 1];
		nPosY = nY + nMoveY[nCommand - 1];

		//�̵��� �� ������ ���
		if(nPosX < 0 || nPosX >= nSizeX || nPosY < 0 || nPosY >= nSizeY)
			continue;

		//ȸ��
		DiceRoll(vDice, nCommand);


		//�Ʒ� ���� ����
		if (vMap[nPosX][nPosY] == 0)
			vMap[nPosX][nPosY] = vDice[1];
		else
		{
			vDice[1] = vMap[nPosX][nPosY];
			vMap[nPosX][nPosY] = 0;
		}

		//��ġ�� �̵�
		nX = nPosX;
		nY = nPosY;

		//�� ���
		cout << vDice[0] << '\n';
	}


	////////////////////////////////////
	system("pause");
	return 0;
}