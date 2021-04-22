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
typedef pair<p, p> pp;
typedef vector<vector<char>> vmap;

//custum function


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//���� �ϳ� ����� ���� ������ �Ķ� ������ ��ġ�� �����ϴ� ������ ����
	//�ʿ� ���� ������ �Ķ� ������ ��ġ�� ǥ��
	//�ߺ� üũ�� set�� ���ؼ� ����
	//bps������� ����
	//Declaration
	int nSizeX, nSizeY, nResult = -1;
	vmap vMap;
	p pR, pB, pO;
	set<pp> s;
	queue<pair<pp, int>> q;

	//Input
	cin >> nSizeX >> nSizeY;
	vMap = vmap(nSizeX, vector<char>(nSizeY));
	for (int i = 0; i < nSizeX; i++)
	{
		for (int j = 0; j < nSizeY; j++)
		{
			cin >> vMap[i][j];

			if (vMap[i][j] == 'R')
				pR = p(i, j);
			if (vMap[i][j] == 'B')
				pB = p(i, j);
			if (vMap[i][j] == 'O')
				pO = p(i, j);
		}
	}

	//Solution
	vMap[pR.first][pR.second] = '.';
	vMap[pB.first][pB.second] = '.';
	q.push(make_pair(pp(pR, pB), 1));

	while (!q.empty())
	{
		p tempR, tempB;
		vmap tempMap;
		bool bB_Finish = false;

		pR = q.front().first.first;
		pB = q.front().first.second;
		int nCount = q.front().second;

		if (nCount > 10)
		{
			nResult = -1;
			break;
		}

		q.pop();

		//�ߺ��Ǹ� ��ŵ
		if (s.find(pp(pR, pB)) == s.end())
			s.insert(pp(pR, pB));
		else
			continue;

		//R�� B�� Map���� ����
		tempMap = vMap;

		//R�� B�� ���� ������ ��� - �����̵�
		//if (pR.first == pB.first)
		{
			bool bR_firstMove = pR.second > pB.second;

			//R�� ���� ������ ��
			if (bR_firstMove)
			{
				//������
				//R�̵�
				tempR = pR;
				tempB = pB;
				tempMap = vMap;
				bB_Finish = false;

				while (true)
				{
					if (tempMap[tempR.first][tempR.second + 1] == '.')
						tempR.second++;
					else if (tempMap[tempR.first][tempR.second + 1] == '#')
					{
						tempMap[tempR.first][tempR.second] = 'R';
						break;
					}						
					else if (tempMap[tempR.first][tempR.second + 1] == 'O')
					{
						nResult = nCount;
						break;
					}
				}


				//B�̵�
				while (true)
				{
					if (tempMap[tempB.first][tempB.second + 1] == '.')
						tempB.second++;
					else if (tempMap[tempB.first][tempB.second + 1] == '#' || tempMap[tempB.first][tempB.second + 1] == 'R')
					{
						tempMap[tempB.first][tempB.second] = 'B';
						break;
					}
					else if (tempMap[tempB.first][tempB.second + 1] == 'O')
					{
						bB_Finish = true;
						break;
					}
				}

				if (nResult != -1 && !bB_Finish)
					break;

				if (!bB_Finish)
					q.push(make_pair(pp(tempR, tempB), nCount + 1));
				else
					nResult = -1;

				//����
				//R�̵�
				tempR = pR;
				tempB = pB;
				tempMap = vMap;
				bB_Finish = false;
				
				//B�̵�
				while (true)
				{
					if (tempMap[tempB.first][tempB.second - 1] == '.')
						tempB.second--;
					else if (tempMap[tempB.first][tempB.second - 1] == '#')
					{
						tempMap[tempB.first][tempB.second] = 'B';
						break;
					}
					else if (tempMap[tempB.first][tempB.second - 1] == 'O')
					{
						bB_Finish = true;
						break;
					}
				}

				//R�̵�
				while (true)
				{
					if (tempMap[tempR.first][tempR.second - 1] == '.')
						tempR.second--;
					else if (tempMap[tempR.first][tempR.second - 1] == '#' || tempMap[tempR.first][tempR.second - 1] == 'B')
					{
						tempMap[tempR.first][tempR.second] = 'R';
						break;
					}
					else if (tempMap[tempR.first][tempR.second - 1] == 'O')
					{
						nResult = nCount;
						break;
					}
				}

				if (nResult != -1 && !bB_Finish)
					break;

				if (!bB_Finish)
					q.push(make_pair(pp(tempR, tempB), nCount + 1));
				else
					nResult = -1;
			}
			else
			{
				//������
				tempR = pR;
				tempB = pB;
				tempMap = vMap;
				bB_Finish = false;

				//B�̵�
				while (true)
				{
					if (tempMap[tempB.first][tempB.second + 1] == '.')
						tempB.second++;
					else if (tempMap[tempB.first][tempB.second + 1] == '#' || tempMap[tempB.first][tempB.second + 1] == 'R')
					{
						tempMap[tempB.first][tempB.second] = 'B';
						break;
					}
					else if (tempMap[tempB.first][tempB.second + 1] == 'O')
					{
						bB_Finish = true;
						break;
					}
				}

				//R�̵�
				while (true)
				{
					if (tempMap[tempR.first][tempR.second + 1] == '.')
						tempR.second++;
					else if (tempMap[tempR.first][tempR.second + 1] == '#' || tempMap[tempR.first][tempR.second + 1] == 'B')
					{
						tempMap[tempR.first][tempR.second] = 'R';
						break;
					}
					else if (tempMap[tempR.first][tempR.second + 1] == 'O')
					{
						nResult = nCount;
						break;
					}
				}

				if (nResult != -1 && !bB_Finish)
					break;

				if (!bB_Finish)
					q.push(make_pair(pp(tempR, tempB), nCount + 1));
				else
					nResult = -1;

				//����
				//R�̵�
				tempR = pR;
				tempB = pB;
				tempMap = vMap;
				bB_Finish = false;

				//R�̵�
				while (true)
				{
					if (tempMap[tempR.first][tempR.second - 1] == '.')
						tempR.second--;
					else if (tempMap[tempR.first][tempR.second - 1] == '#' || tempMap[tempR.first][tempR.second - 1] == 'B')
					{
						tempMap[tempR.first][tempR.second] = 'R';
						break;
					}
					else if (tempMap[tempR.first][tempR.second - 1] == 'O')
					{
						nResult = nCount;
						break;
					}
				}

				//B�̵�
				while (true)
				{
					if (tempMap[tempB.first][tempB.second - 1] == '.')
						tempB.second--;
					else if (tempMap[tempB.first][tempB.second - 1] == '#' || tempMap[tempB.first][tempB.second - 1] == 'R')
					{
						tempMap[tempB.first][tempB.second] = 'B';
						break;
					}
					else if (tempMap[tempB.first][tempB.second - 1] == 'O')
					{
						bB_Finish = true;
						break;
					}
				}

				if (nResult != -1 && !bB_Finish)
					break;

				if (!bB_Finish)
					q.push(make_pair(pp(tempR, tempB), nCount + 1));
				else
					nResult = -1;
			}
		}

		//R�� B�� ���� ������ ��� - �����̵�
		//if (pR.second == pB.second)
		{
			bool bR_firstMove = pR.first > pB.first;

			//R�� ���� ������ ��
			if (bR_firstMove)
			{
				//�Ʒ�
				//R�̵�
				tempR = pR;
				tempB = pB;
				tempMap = vMap;
				bB_Finish = false;

				while (true)
				{
					if (tempMap[tempR.first + 1][tempR.second] == '.')
						tempR.first++;
					else if (tempMap[tempR.first + 1][tempR.second] == '#')
					{
						tempMap[tempR.first][tempR.second] = 'R';
						break;
					}
					else if (tempMap[tempR.first + 1][tempR.second] == 'O')
					{
						nResult = nCount;
						break;
					}
				}

				//B�̵�
				while (true)
				{
					if (tempMap[tempB.first + 1][tempB.second] == '.')
						tempB.first++;
					else if (tempMap[tempB.first + 1][tempB.second] == '#' || tempMap[tempB.first + 1][tempB.second] == 'R')
					{
						tempMap[tempB.first][tempB.second] = 'B';
						break;
					}
					else if (tempMap[tempB.first + 1][tempB.second] == 'O')
					{
						bB_Finish = true;
						break;
					}
				}

				if (nResult != -1 && !bB_Finish)
					break;

				if (!bB_Finish)
					q.push(make_pair(pp(tempR, tempB), nCount + 1));
				else
					nResult = -1;

				//��
				tempR = pR;
				tempB = pB;
				tempMap = vMap;
				bB_Finish = false;

				//B�̵�
				while (true)
				{
					if (tempMap[tempB.first - 1][tempB.second] == '.')
						tempB.first--;
					else if (tempMap[tempB.first - 1][tempB.second] == '#')
					{
						tempMap[tempB.first][tempB.second] = 'B';
						break;
					}
					else if (tempMap[tempB.first - 1][tempB.second] == 'O')
					{
						bB_Finish = true;
						break;
					}
				}

				//R�̵�
				while (true)
				{
					if (tempMap[tempR.first - 1][tempR.second] == '.')
						tempR.first--;
					else if (tempMap[tempR.first - 1][tempR.second] == '#' || tempMap[tempR.first - 1][tempR.second] == 'B')
					{
						tempMap[tempR.first][tempR.second] = 'R';
						break;
					}
					else if (tempMap[tempR.first - 1][tempR.second] == 'O')
					{
						nResult = nCount;
						break;
					}
				}

				if (nResult != -1 && !bB_Finish)
					break;

				if (!bB_Finish)
					q.push(make_pair(pp(tempR, tempB), nCount + 1));
				else
					nResult = -1;
			}
			else
			{
				//������
				tempR = pR;
				tempB = pB;
				tempMap = vMap;
				bB_Finish = false;

				//B�̵�
				while (true)
				{
					if (tempMap[tempB.first + 1][tempB.second] == '.')
						tempB.first++;
					else if (tempMap[tempB.first + 1][tempB.second] == '#' || tempMap[tempB.first + 1][tempB.second] == 'R')
					{
						tempMap[tempB.first][tempB.second] = 'B';
						break;
					}
					else if (tempMap[tempB.first + 1][tempB.second] == 'O')
					{
						bB_Finish = true;
						break;
					}
				}

				//R�̵�
				while (true)
				{
					if (tempMap[tempR.first + 1][tempR.second] == '.')
						tempR.first++;
					else if (tempMap[tempR.first + 1][tempR.second] == '#' || tempMap[tempR.first + 1][tempR.second] == 'B')
					{
						tempMap[tempR.first][tempR.second] = 'R';
						break;
					}
					else if (tempMap[tempR.first + 1][tempR.second] == 'O')
					{
						nResult = nCount;
						break;
					}
				}

				if (nResult != -1 && !bB_Finish)
					break;

				if (!bB_Finish)
					q.push(make_pair(pp(tempR, tempB), nCount + 1));
				else
					nResult = -1;

				//����
				//R�̵�
				tempR = pR;
				tempB = pB;
				tempMap = vMap;
				bB_Finish = false;

				//R�̵�
				while (true)
				{
					if (tempMap[tempR.first - 1][tempR.second] == '.')
						tempR.first--;
					else if (tempMap[tempR.first - 1][tempR.second] == '#' || tempMap[tempR.first - 1][tempR.second] == 'B')
					{
						tempMap[tempR.first][tempR.second] = 'R';
						break;
					}
					else if (tempMap[tempR.first - 1][tempR.second] == 'O')
					{
						nResult = nCount;
						break;
					}
				}

				//B�̵�
				while (true)
				{
					if (tempMap[tempB.first - 1][tempB.second] == '.')
						tempB.first--;
					else if (tempMap[tempB.first - 1][tempB.second] == '#' || tempMap[tempB.first - 1][tempB.second] == 'R')
					{
						tempMap[tempB.first][tempB.second] = 'B';
						break;
					}
					else if (tempMap[tempB.first - 1][tempB.second] == 'O')
					{
						bB_Finish = true;
						break;
					}
				}

				if (nResult != -1 && !bB_Finish)
					break;

				if (!bB_Finish)
					q.push(make_pair(pp(tempR, tempB), nCount + 1));
				else
					nResult = -1;
			}
		}
	}


	//Output
	cout << nResult << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}