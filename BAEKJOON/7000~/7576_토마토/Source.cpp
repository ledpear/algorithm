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
typedef unsigned long long ull;
typedef pair<ull, ull> p;
typedef vector<vector<int>> vmap;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//�Է°��� ���� �� ��ġ�� q�� �װ�
	//��ȸ�Ҷ��� q�� �ִ� ���� �� ���鼭 temp�� �װ� temp�� q�� �����ϸ鼭 ��¥ ����
	//�׶� q�� ������� 0�� ���� ���� �丶���� ��ġ�� ������ ��¥�� ���� �ƴϸ� -1 ����

	int nX, nY, nScore = 0, nCount = 0, nDay = 0;
	cin >> nY >> nX;
	vmap vMap = vmap(nX, vector<int>(nY));
	queue<p> q;

	for (int i = 0; i < nX; i++)
	{
		for (int j = 0; j < nY; j++)
		{
			cin >> vMap[i][j];
			if (vMap[i][j] == 0)
				nScore++;
			if (vMap[i][j] == 1)
				q.push(p(i,j));
		}
	}

	while (true)
	{
		queue<p> qTemp;

		while (!q.empty())
		{
			p pos = q.front();
			q.pop();

			int nPosX, nPosY;
			nPosX = pos.first;
			nPosY = pos.second;

			if (nPosX != 0 && vMap[nPosX - 1][nPosY] == 0)
			{
				qTemp.push(p(nPosX - 1, nPosY));
				vMap[nPosX - 1][nPosY] = 1;
				nCount++;
			}				
			if (nPosY != 0 && vMap[nPosX][nPosY - 1] == 0)
			{
				qTemp.push(p(nPosX, nPosY - 1));
				vMap[nPosX][nPosY - 1] = 1;
				nCount++;
			}
			if (nPosX != nX - 1 && vMap[nPosX + 1][nPosY] == 0)
			{
				qTemp.push(p(nPosX + 1, nPosY));
				vMap[nPosX + 1][nPosY] = 1;
				nCount++;
			}
			if (nPosY != nY - 1 && vMap[nPosX][nPosY + 1] == 0)
			{
				qTemp.push(p(nPosX, nPosY + 1));
				vMap[nPosX][nPosY + 1] = 1;
				nCount++;
			}				
		}

		if (qTemp.empty())
			break;
		else
		{
			nDay++;
			q = qTemp;
		}			
	}

	if (nCount == nScore)
		cout << nDay << '\n';
	else
		cout << "-1\n";


	system("pause");

	return 0;
}