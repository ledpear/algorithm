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

		//�� �����̸鼭 �̳׶��� ��� Ž��
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
	//�� ���� �Ʒ��κ��� �ٴ� �Ǵ� �ٸ� �̳׶��� ����� Ȯ��
	int count = 0; // ��ŭ ����������
	bool search = false;

	int left = fallinfo.left;
	int right = fallinfo.rigth;
	vector<int> Floor = fallinfo.floor;

	//�󸶳� ���������ϴ� Ž��
	while (true)
	{
		++count;
		for (int index(left); index <= right; ++index)
		{
			//Ž������ ���� ���� ���� ��
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

	//���� �̵�
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//��Ʈ������ ��ĭ�� 0 �̳׶��� 1�� ǥ��
	//ó���� ���ʿ��� �� ������ ������ �� ������ ���� ������ �ݺ��ؼ� ���� ������
	//1. ���밡 �̳׶��� �ε��� �ı��Ǹ� 
	//2. ��濡 �̳׶��� �ִ��� Ȯ�� �ִٸ�
	//3. �ش� �̳׶��� �ٴ��̶� �پ��ִ��� dfs(or bfs)�� Ȯ��[�Ʒ� �� �� �� ������ Ž��] - �ٴڿ� �����ϸ� �ٷ� ����
	//4. �ٴڿ� ����Ǿ����� ���� Ŭ�����ʹ� ����ó��
	//5. ����ó���� Ž���� 1���� �迭�� �ش� Ŭ�����Ϳ� ���� �Ʒ� ��ġ�� �����ؼ� ��ĭ�� �������鼭 �ε������� Ȯ��
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

	bool bLeft = true;	//true�� ����->������ false�� ������->����
	for (int nLine : vCmd)
	{
		nLine = 8 - nLine;
		int nRise(1), nLine_index(0);
		if (!bLeft)
		{
			nRise = -1;
			nLine_index = C - 1;
		}

		//���� ������ ���
		for (nLine_index; 0 <= nLine_index && nLine_index < C; nLine_index += nRise)
		{
			if (vMatrix[nLine][nLine_index])
			{
				//�̳׶� �İ� ó�� 1 -> 0
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

			//�ܰ��� �ƴϰ� �̳׶��̸� �����ϴ� Ŭ������ Ž��
			if (nPosX >= 0 && nPosY >= 0 && nPosX < R && nPosY < C && vMatrix[nPosX][nPosY] && !vVisit[nPosX][nPosY])
			{
				result = DFS(nPosX, nPosY, fallinfo, vMatrix, vVisit);

				//�����ϴ� Ŭ�����Ͱ� ������
				if (!result)
				{
					//���� ó���� �ϰ�

					//Ž�� ���� - �����ϴ� Ŭ����Ʈ�� �ϳ��ۿ� �����Ƿ�
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