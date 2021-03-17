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
typedef pair<int, bool> node;
typedef vector<vector<int>> vmap;

//custum function
void Move(vmap& vMap, int nSize, int nDir, int &nMax)
{
	if (nDir == 0)	//������
	{
		for(int i = 0; i < nSize; i++)
		{
			vector<int> vNewBlock(nSize, 0);
			int oldPos = nSize - 1;
			int newPos = oldPos;

			while (oldPos >= 0)
			{
				if (vMap[i][oldPos] == 0)
				{
					--oldPos;
					continue;
				}
				
				//0�̸� ������ ���� �ִ´�
				if (vNewBlock[newPos] == 0)	
				{
					vNewBlock[newPos] = vMap[i][oldPos];
					--oldPos;
				}
				//0�� �ƴϰ� new�� old�� ���� ������ ��ġ�� ���� new�� �Ѿ��
				else if (vNewBlock[newPos] == vMap[i][oldPos]) 
				{
					vNewBlock[newPos] *= 2;
					nMax = max(nMax, vNewBlock[newPos]);
					--newPos;
					--oldPos;					
				}
				else
				{
					--newPos;
				}
			}
			vMap[i] = vNewBlock;
		}
	}
	else if (nDir == 1)	//�Ʒ�
	{
		for(int i = 0; i < nSize; i++)
		{
			vector<int> vNewBlock(nSize, 0);
			int oldPos = nSize - 1;
			int newPos = oldPos;

			while (oldPos >= 0)
			{
				if (vMap[oldPos][i] == 0)
				{
					--oldPos;
					continue;
				}
				
				//0�̸� ������ ���� �ִ´�
				if (vNewBlock[newPos] == 0)	
				{
					vNewBlock[newPos] = vMap[oldPos][i];
					--oldPos;
				}
				//0�� �ƴϰ� new�� old�� ���� ������ ��ġ�� ���� new�� �Ѿ��
				else if (vNewBlock[newPos] == vMap[oldPos][i])
				{
					vNewBlock[newPos] *= 2;
					nMax = max(nMax, vNewBlock[newPos]);
					--newPos;
					--oldPos;
				}
				else
				{
					--newPos;
				}
			}
			//����
			for (int j = 0; j < nSize; j++)
				vMap[j][i] = vNewBlock[j];
		}
	}
	else if (nDir == 2)	//����
	{
		for (int i = 0; i < nSize; i++)
		{
			vector<int> vNewBlock(nSize, 0);
			int oldPos = 0;
			int newPos = oldPos;

			while (oldPos < nSize)
			{
				if (vMap[i][oldPos] == 0)
				{
					++oldPos;
					continue;
				}

				//0�̸� ������ ���� �ִ´�
				if (vNewBlock[newPos] == 0)
				{
					vNewBlock[newPos] = vMap[i][oldPos];
					++oldPos;
				}
				//0�� �ƴϰ� new�� old�� ���� ������ ��ġ�� ���� new�� �Ѿ��
				else if (vNewBlock[newPos] == vMap[i][oldPos])
				{
					vNewBlock[newPos] *= 2;
					nMax = max(nMax, vNewBlock[newPos]);
					++newPos;
					++oldPos;
				}
				else
				{
					++newPos;
				}
			}
			vMap[i] = vNewBlock;
		}
	}
	else if (nDir == 3)	//��
	{
		for (int i = 0; i < nSize; i++)
		{
			vector<int> vNewBlock(nSize, 0);
			int oldPos = 0;
			int newPos = oldPos;

			while (oldPos < nSize)
			{
				if (vMap[oldPos][i] == 0)
				{
					++oldPos;
					continue;
				}

				//0�̸� ������ ���� �ִ´�
				if (vNewBlock[newPos] == 0)
				{
					vNewBlock[newPos] = vMap[oldPos][i];
					++oldPos;
				}
				//0�� �ƴϰ� new�� old�� ���� ������ ��ġ�� ���� new�� �Ѿ��
				else if (vNewBlock[newPos] == vMap[oldPos][i])
				{
					vNewBlock[newPos] *= 2;
					nMax = max(nMax, vNewBlock[newPos]);
					++newPos;
					++oldPos;
				}
				else
				{
					++newPos;
				}
			}
			//����
			for (int j = 0; j < nSize; j++)
				vMap[j][i] = vNewBlock[j];
		}
	}
}

void MapPrint(const vmap& vMap)
{
	int nSize = vMap.size();
	
	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			cout << vMap[i][j] << ' ';
		}
		cout << '\n';
	}
}

void BT(vmap& vMap, int& nMax, int nCount = 0)
{
	int nSize = vMap.size();
	vmap vTemp = vMap;

	if (nCount == 5)
		return;

	for (int i = 0; i < 4; i++)
	{
		Move(vMap, nSize, i, nMax);
		BT(vMap, nMax, nCount + 1);
		vMap = vTemp;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//���� ��ϸ� �����ϴ� ���� ���� �Ǵ� �Ź� �ʱ�ȭ
	//0�� ��ĭ �������� ��� ���
	//Declaration
	int nSize, nMax = 0;
	vmap vMap;
	vector<vector<bool>> vUsed;

	//Input
	cin >> nSize;
	vMap = vmap(nSize, vector<int>(nSize));
	vUsed = vector<vector<bool>>(nSize, vector<bool>(nSize, false));;
	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			cin >> vMap[i][j];
			nMax = max(nMax, vMap[i][j]);
		}
	}

	//Solution
	BT(vMap, nMax);

	//Output
	cout << nMax << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}