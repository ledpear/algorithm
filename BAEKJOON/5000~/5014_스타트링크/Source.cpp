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
	//1���� �迭�� BFS������� Ž��
	//Declaration
	int nSize, nStart, nTarget, nResult = -1;
	int nMove[2];	//up, down
	queue<p> q;
	vector<bool> vVisit;

	//Input
	cin >> nSize >> nStart >> nTarget >> nMove[0] >> nMove[1];
	nMove[1] *= -1;
	vVisit = vector<bool>(nSize + 1, false);

	//Solution
	q.push(p(nStart, 0));

	while (!q.empty())
	{
		int nPos = q.front().first;
		int nCnt = q.front().second;
		q.pop();

		//�������� ����
		if (nPos == nTarget)
		{
			nResult = nCnt;
			break;
		}

		//�湮�� �� ������ �ǳʶٱ�
		if (vVisit[nPos])	continue;
		vVisit[nPos] = true;

		//ť�� �߰�
		int nMovePos = 0;
		for (int i = 0; i < 2; i++)
		{
			nMovePos = nPos + nMove[i];
			if (nMovePos > 0 && nMovePos <= nSize)
			{
				q.push(p(nMovePos, nCnt + 1));
			}
		}
	}

	//Output
	if (nResult == -1)
		cout << "use the stairs\n";
	else
		cout << nResult << '\n';

	////////////////////////////////////
	return 0;
}