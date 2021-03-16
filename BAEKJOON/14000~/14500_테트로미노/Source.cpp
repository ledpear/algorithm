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
void Tetromino(int nSizeX, int nSizeY, const vmap& vMap, int nX, int nY, int &nMax)
{
	vector<vector<p>> vTetrominoPattern = vector<vector<p>>(5);

	//(x, y)
	vTetrominoPattern[0] = { p(0, 0), p(1, 0), p(2, 0), p(3, 0) };
	vTetrominoPattern[1] = { p(0, 0), p(1, 0), p(1, 1), p(0, 1) };
	vTetrominoPattern[2] = { p(0, 0), p(0, 1), p(0, 2), p(1, 2) };
	vTetrominoPattern[3] = { p(0, 0), p(0, 1), p(1, 1), p(1, 2) };
	vTetrominoPattern[4] = { p(0, 0), p(1, 0), p(2, 0), p(1, 1) };

	for (int i = 0; i < 5; i++)	//���� ��ȸ
	{
		for (int j = 0; j < 8; j++) //����, ��Ī ��ȸ
		{
			int nResult = 0;
			int posX, posY;
			int nDir = j % 2;
			int nSym = j / 2;

			//���� ���� - ���� > 
			for (int k = 0; k < 4; k++)	//��Ʈ�ι̳� ���� ���
			{
				// ���� ����
				if (nDir == 0)	//�⺻
				{
					posX = vTetrominoPattern[i][k].first;
					posY = vTetrominoPattern[i][k].second;
				}
				else if (nDir == 1)	// 90�� ȸ��
				{
					posX = vTetrominoPattern[i][k].second;
					posY = vTetrominoPattern[i][k].first;
				}

				// ��Ī����
				if (nSym == 0)	//�⺻
				{
					posX = nX + posX;
					posY = nY + posY;
				}
				else if (nSym == 1)	// ���� ����
				{
					posX = nX - posX;
					posY = nY + posY;
				}
				else if (nSym == 2)	// �¿� ����
				{
					posX = nX + posX;
					posY = nY - posY;
				}
				else if (nSym == 3)	// �����¿� ����
				{
					posX = nX - posX;
					posY = nY - posY;
				}

				// ��Ʈ�ι̳� ���� ���
				if (posX >= 0 && posX < nSizeX && posY >= 0 && posY < nSizeY)
				{
					nResult += vMap[posX][posY];
				}
				else
				{
					nResult = 0;
					break;
				}
			}

			if (nMax < nResult)
				nMax = nResult;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int nSizeX, nSizeY, nMax = 0;
	vmap vMap;

	//Input
	cin >> nSizeX >> nSizeY;
	vMap = vmap(nSizeX, vector<int>(nSizeY));

	for (int i = 0; i < nSizeX; i++)
	{
		for (int j = 0; j < nSizeY; j++)
		{
			cin >> vMap[i][j];
		}
	}

	//Solution
	for (int i = 0; i < nSizeX; i++)
	{
		for (int j = 0; j < nSizeY; j++)
		{
			Tetromino(nSizeX, nSizeY, vMap, i, j, nMax);
		}
	}

	//Output
	cout << nMax << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}