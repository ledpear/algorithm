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
typedef vector<int> point;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//�Է°��� ���� �� ��ġ�� q�� �װ�
	//��ȸ�Ҷ��� q�� �ִ� ���� �� ���鼭 temp�� �װ� temp�� q�� �����ϸ鼭 ��¥ ����
	//�׶� q�� ������� 0�� ���� ���� �丶���� ��ġ�� ������ ��¥�� ���� �ƴϸ� -1 ����

	int nX, nY, nZ, nScore = 0, nCount = 0, nDay = 0;
	cin >> nY >> nX >> nZ;
	vector<vmap> vMap = vector<vmap>(nZ, vmap(nX, vector<int>(nY)));
	//vmap vMap = vmap(nX, vector<int>(nY));
	queue<point> q;

	for (int k = 0; k < nZ; k++)
	{
		for (int i = 0; i < nX; i++)
		{
			
			for (int j = 0; j < nY; j++)
			{
				
				cin >> vMap[k][i][j];
				if (vMap[k][i][j] == 0)
					nScore++;
				if (vMap[k][i][j] == 1)
					q.push({ k,i,j });
			}
		}
	}

	while (true)
	{
		queue<point> qTemp;

		while (!q.empty())
		{
			point pos = q.front();
			q.pop();

			int nPosX, nPosY, nPosZ;
			nPosZ = pos[0];
			nPosX = pos[1];
			nPosY = pos[2];
			
			if (nPosX != 0 && vMap[nPosZ][nPosX - 1][nPosY] == 0)
			{
				qTemp.push({nPosZ, nPosX - 1, nPosY });
				vMap[nPosZ][nPosX - 1][nPosY] = 1;
				nCount++;
			}				
			if (nPosY != 0 && vMap[nPosZ][nPosX][nPosY - 1] == 0)
			{
				qTemp.push({ nPosZ, nPosX, nPosY - 1 });
				vMap[nPosZ][nPosX][nPosY - 1] = 1;
				nCount++;
			}
			if (nPosX != nX - 1 && vMap[nPosZ][nPosX + 1][nPosY] == 0)
			{
				qTemp.push({ nPosZ, nPosX + 1, nPosY });
				vMap[nPosZ][nPosX + 1][nPosY] = 1;
				nCount++;
			}
			if (nPosY != nY - 1 && vMap[nPosZ][nPosX][nPosY + 1] == 0)
			{
				qTemp.push({ nPosZ, nPosX, nPosY + 1 });
				vMap[nPosZ][nPosX][nPosY + 1] = 1;
				nCount++;
			}		
			if (nPosZ != 0 && vMap[nPosZ - 1][nPosX][nPosY] == 0)
			{
				qTemp.push({ nPosZ - 1, nPosX, nPosY });
				vMap[nPosZ - 1][nPosX][nPosY] = 1;
				nCount++;
			}
			if (nPosZ != nZ - 1 && vMap[nPosZ + 1][nPosX][nPosY] == 0)
			{
				qTemp.push({ nPosZ + 1, nPosX, nPosY });
				vMap[nPosZ + 1][nPosX][nPosY] = 1;
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