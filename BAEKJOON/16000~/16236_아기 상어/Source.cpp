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
typedef pair<int, int> p;
typedef pair<p, int> pi;
typedef vector<vector<int>> vmap;

//custum function
bool compare(pi a, pi b)
{
	if (a.second == b.second)
	{
		if (a.first.first == b.first.first)
			return a.first.second < b.first.second;
		else
			return a.first.first < b.first.first;
	}
	else
		return a.second < b.second;
}
void BFS(vmap& vMap, p &pShark, int nSharkSize, vector<pi>& vArr)
{
	int nSize = vMap.size(), nResult = -1;
	int nMoveX[4] = { -1, 0, 0, 1 };
	int nMoveY[4] = { 0, -1, 1, 0 };
	vmap vVisit(nSize, vector<int>(nSize, false));

	queue<pair<p, int>> q;
	q.push(make_pair(pShark, 0));
	vVisit[pShark.first][pShark.second] = true;

	while (!q.empty())
	{
		int nNowX, nNowY, nDist;
		nNowX = q.front().first.first;
		nNowY = q.front().first.second;
		nDist = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nPosX, nPosY;
			nPosX = nNowX + nMoveX[i];
			nPosY = nNowY + nMoveY[i];

			if (nPosX >= 0 && nPosX < nSize && nPosY >= 0 && nPosY < nSize // ���� ����ó��
				&& nSharkSize >= vMap[nPosX][nPosY] //���� �۰ų� ���ƾ� ���
				&& vVisit[nPosX][nPosY] == false//�湮���� ���� ���� �߰�
				)
			{
				if (vMap[nPosX][nPosY] != nSharkSize && vMap[nPosX][nPosY] != 0)
					vArr.push_back(pi(p(nPosX, nPosY), nDist + 1));
				vVisit[nPosX][nPosY] = true;
				q.push(make_pair(p(nPosX, nPosY), nDist + 1));
			}
		}
	}
}

void Map_Print(const vmap& vMap)
{
	int nSizeX = vMap.size();
	int nSizeY = vMap[0].size();

	for (int i = 0; i < nSizeX; i++)
	{
		for (int j = 0; j < nSizeY; j++)
			cout << vMap[i][j] << ' ';
		cout << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//����� ����ũ��� 2
	//1ĭ�� 1�ʽ� �ɸ�
	//�ڽź��� ū�ų� ���� ������ ������
	//ū ������ ������������ ���� ������ �������� ���� ���� ����
	//�ڽ��� ũ�⸸ŭ ����⸦ ������ 1��Ŀ��
	//bfs�� �ڽź��� ���� ���尡��� ������� ��ġ�� ã�´�
	//
	//Declaration
	int nSize, nSum = 0, nCount = 0;
	p pShark;
	vmap vMap;
	vector<pi> vArr;
	int nSharkSize = 2;

	//Input
	cin >> nSize;
	vMap = vmap(nSize, vector<int>(nSize));
	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			cin >> vMap[i][j];
			if (vMap[i][j] == 9)
				pShark = p(i, j);
		}
	}

	//Solution
	while (true)
	{
		vArr.clear();
		BFS(vMap, pShark, nSharkSize, vArr);

		if (vArr.size() == 0)//���� �� �ִ� ����Ⱑ ����
			break;
		else
		{
			if (vArr.size() != 1)
				sort(vArr.begin(), vArr.end(), compare);

			int nPosX, nPosY, nDist;
			nPosX = vArr[0].first.first;
			nPosY = vArr[0].first.second;
			nDist = vArr[0].second;

			nSum += nDist;
			vMap[pShark.first][pShark.second] = 0;
			vMap[nPosX][nPosY] = 9;
			pShark.first = nPosX;
			pShark.second = nPosY;

			++nCount;

			if (nCount == nSharkSize)
			{
				nCount = 0;
				++nSharkSize;
			}
		}
		// 
		// 		cout << '\n';
		// 		Map_Print(vMap);
		// 		cout << "count : " << nCount << '\n';
		// 		cout << "Size  : " << nSharkSize << '\n';
		// 		cout << "Sum   : " << nSum << '\n';
	}

	//Output
	cout << nSum << '\n';

	////////////////////////////////////
	//system("pause");
	return 0;
}