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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//���ʿ��� ���������� �� ���� �����ʿ��� �������� ���� ���ʴ� �Ʒ��� �������� ��츸 üũ
	//������ �迭�� �����ϰ� ���� ��ġ�ų� �ȵǴ� ������ ������ falseó��
	//Declaration
	int nMapSize, nSize, nCount = 0;
	vmap vMap;

	//Input
	cin >> nMapSize >> nSize;
	vMap = vmap(nMapSize, vector<int>(nMapSize));
	for (int i = 0; i < nMapSize; i++)
	{
		for (int j = 0; j < nMapSize; j++)
		{
			cin >> vMap[i][j];
		}
	}

	//Solution
	//����
	for (int i = 0; i < nMapSize; i++)
	{
		bool bResult = true;
		vector<int> vArr(nMapSize, 0);	
		for (int j = 0; j < nMapSize - 1; j++)
		{
			if(vMap[i][j] - vMap[i][j + 1] == 0)
				continue;
			
			if (vMap[i][j] - vMap[i][j + 1] == 1)
			{
				if (nMapSize - j <= nSize)
				{
					bResult = false;
					break;
				}

				int nTemp = vMap[i][j + 1];
				for (int k = 1; k <= nSize; k++)
				{
					if (nTemp != vMap[i][j + k] || vArr[j + k] != 0)
					{
						bResult = false;
						break;
					}
					else
					{
						vArr[j + k] = 1;
					}
				}
			}
			else if(abs(vMap[i][j] - vMap[i][j + 1]) >= 2)
				bResult = false;
		}

		for (int j = nMapSize - 1; j >= 1; j--)
		{
			if (vMap[i][j] - vMap[i][j - 1] == 0)
				continue;

			if (vMap[i][j] - vMap[i][j - 1] == 1)
			{
				if (j < nSize)
				{
					bResult = false;
					break;
				}

				int nTemp = vMap[i][j - 1];
				for (int k = 1; k <= nSize; k++)
				{
					if (nTemp != vMap[i][j - k] || vArr[j - k] != 0)
					{
						bResult = false;
						break;
					}
					else
					{
						vArr[j - k] = 1;
					}
				}
			}
			else if (abs(vMap[i][j] - vMap[i][j - 1]) >= 2)
				bResult = false;
		}

		if (bResult == true)
			++nCount;
	}

	//����
	for (int i = 0; i < nMapSize; i++)
	{
		bool bResult = true;
		vector<int> vArr(nMapSize, 0);
		for (int j = 0; j < nMapSize - 1; j++)
		{
			if (vMap[j][i] - vMap[j + 1][i] == 0)
				continue;

			if (vMap[j][i] - vMap[j + 1][i] == 1)
			{
				if (nMapSize - j <= nSize)
				{
					bResult = false;
					break;
				}

				int nTemp = vMap[j + 1][i];
				for (int k = 1; k <= nSize; k++)
				{
					if (nTemp != vMap[j + k][i] || vArr[j + k] != 0)
					{
						bResult = false;
						break;
					}
					else
					{
						vArr[j + k] = 1;
					}
				}
			}
			else if (abs(vMap[j][i] - vMap[j + 1][i]) >= 2)
				bResult = false;
		}

		for (int j = nMapSize - 1; j >= 1; j--)
		{
			if (vMap[j][i] - vMap[j - 1][i] == 0)
				continue;

			if (vMap[j][i] - vMap[j - 1][i] == 1)
			{
				if (j < nSize)
				{
					bResult = false;
					break;
				}

				int nTemp = vMap[j - 1][i];
				for (int k = 1; k <= nSize; k++)
				{
					if (nTemp != vMap[j - k][i] || vArr[j - k] != 0)
					{
						bResult = false;
						break;
					}
					else
					{
						vArr[j - k] = 1;
					}
				}
			}
			else if (abs(vMap[j][i] - vMap[j - 1][i]) >= 2)
				bResult = false;
		}

		if (bResult == true)
			++nCount;
	}

	//Output
	cout << nCount << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}