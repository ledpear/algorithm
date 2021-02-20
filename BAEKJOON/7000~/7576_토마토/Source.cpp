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

	//입력값을 받을 때 위치를 q로 쌓고
	//순회할때는 q에 있는 것을 다 돌면서 temp에 쌓고 temp를 q에 복사하면서 날짜 진행
	//그때 q가 비었을때 0의 값과 익은 토마토의 수치가 같으면 날짜를 리턴 아니면 -1 리턴

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