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

		//�� �����̸鼭 �̳׶��� ��� Ž��
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

		//�� �����̸鼭 �̳׶��� ��� Ž��
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
	//Ŭ�����͸� �� Ž���ϸ鼭 �ش� ��� Ŭ�����͸� �� 0���� �ٲٰ� ���ο� �迭�� �̵��� ����� �����ϰ� Ž���� ������ ����
	//�� �� �ٽ� Ž���ؼ� ������ ���������� Ȯ��

	while (true)
	{
		//��ĭ�� �̵�
		//��ü ��ȯ�� �⺻���� ���� �̵��� �̹� �� ��ġ��� ������ �ʴ´�.
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

		//���������� Ȯ��
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
		//dfs�� Ž��
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
	//��Ʈ������ ��ĭ�� 0 �̳׶��� 1�� ǥ��
	//ó���� ���ʿ��� �� ������ ������ �� ������ ���� ������ �ݺ��ؼ� ���� ������
	//1. ���밡 �̳׶��� �ε��� �ı��Ǹ� 
	//2. ��濡 �̳׶��� �ִ��� Ȯ�� �ִٸ�
	//3. �ش� �̳׶��� �ٴ��̶� �پ��ִ��� dfs(or bfs)�� Ȯ��[�Ʒ� �� �� �� ������ Ž��] - �ٴڿ� �����ϸ� �ٷ� ����
	//4. �ٴڿ� ����Ǿ����� ���� Ŭ�����ʹ� ����ó��
	//5. ����ó���� Ž���� 1���� �迭�� �ش� Ŭ�����Ϳ� ���� �Ʒ� ��ġ�� �����ؼ� ��ĭ�� �������鼭 �ε������� Ȯ��
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

	bool bLeft = true;	//true�� ����->������ false�� ������->����
	for (int nLine : vCmd)
	{
		nLine = R - nLine;
		int nRise(1), nLine_index(0);
		if (!bLeft)
		{
			nRise = -1;
			nLine_index = C - 1;
		}

		//���� ������ ���
		bool bCrush = false;

		for (nLine_index; 0 <= nLine_index && nLine_index < C; nLine_index += nRise)
		{
			if (vMatrix[nLine][nLine_index])
			{
				//�̳׶� �İ� ó�� 1 -> 0
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

			//�ܰ��� �ƴϰ� �̳׶��̸� �����ϴ� Ŭ������ Ž��
			if (nPosX >= 0 && nPosY >= 0 && nPosX < R && nPosY < C)
			{
				if (vMatrix[nPosX][nPosY] && !vVisit[nPosX][nPosY])
				{
					result = DFS(nPosX, nPosY, vNode, fallinfo, vMatrix, vVisit);

					//�����ϴ� Ŭ�����Ͱ� ������
					if (!result)
					{
						//���� ó���� �ϰ�
						Fall(vNode, fallinfo, vMatrix);
						//Ž�� ���� - �����ϴ� Ŭ����Ʈ�� �ϳ��ۿ� �����Ƿ�
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