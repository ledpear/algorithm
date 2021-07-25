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

//custum function

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int startPos(0), targetPos(0);
	cin >> startPos >> targetPos;

	//Solution
	int minTime(int(1e9)), searchCount(0);
	queue<vector<int>> btsQueue = queue<vector<int>>();
	vector<int> visit(100001, 1e9);
	btsQueue.push({ startPos, 0 });
	visit[startPos] = 0;

	while (!btsQueue.empty())
	{
		int nowPos = btsQueue.front()[0];
		int moveTime = btsQueue.front()[1];
		btsQueue.pop();

		//ã�� minTime���� ������ Ž���� �ʿ䰡 ����
		if (minTime < moveTime)
		{
			continue;
		}

		//��ġ�� ��ġ�ϸ� ����
		if (nowPos == targetPos)
		{
			if (moveTime < minTime)
			{
				minTime = moveTime;
				searchCount = 1;				
			}
			else if (moveTime == minTime)
			{
				++searchCount;
			}
		}

		//�̵�
		int movePos(0), nextTime(moveTime + 1);
		//1. +1�̵�
		movePos = nowPos + 1;		
		if (movePos <= 100000 && nextTime <= visit[movePos])
		{
			visit[movePos] = nextTime;
			btsQueue.push({ movePos, moveTime + 1 });
		}
		//2. -1�̵�
		movePos = nowPos - 1;
		if (movePos >= 0 && nextTime <= visit[movePos])
		{
			visit[movePos] = nextTime;
			btsQueue.push({ movePos, moveTime + 1 });
		}
		//2. *2�̵�
		movePos = nowPos * 2;
		if (movePos <= 100000 && nextTime <= visit[movePos])
		{
			visit[movePos] = nextTime;
			btsQueue.push({ movePos, moveTime + 1 });
		}
	}

	//Output
	cout << minTime << '\n';
	cout << searchCount << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}