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
#include <unordered_set>

using namespace std;

//define

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;

const int LIMIT = int(1e9);
//custum function

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int startNum(0), targetNum(0);
	cin >> startNum >> targetNum;

	//Solution
	//targetNum에서 startNum까지 BFS로 탐색한다.
	//짝수가 아니라면 2로 나누지 않고
	//뒤가 1이 다니라면 빼지않는다.
	queue<vector<int>> BFS_queue;
	unordered_set<int> BFS_set;
	BFS_queue.push({ targetNum, 0 });
	BFS_set.insert(targetNum);
	int searchCnt = -1;

	while (!BFS_queue.empty())
	{
		int nowNum(BFS_queue.front()[0]), nowCnt(BFS_queue.front()[1]), nextNum(0);
		BFS_queue.pop();

		if (nowNum == startNum)
		{
			searchCnt = nowCnt + 1;
			break;
		}

		if (nowNum % 2 == 0)
		{
			nextNum = int(nowNum / 2);
			if (BFS_set.find(nextNum) == BFS_set.end())
			{
				BFS_queue.push({ nextNum, nowCnt + 1 });
				BFS_set.insert(nextNum);
			}
		}

		if (nowNum % 10 == 1)
		{
			nextNum = int(nowNum / 10);
			if (BFS_set.find(nextNum) == BFS_set.end())
			{
				BFS_queue.push({ nextNum, nowCnt + 1 });
				BFS_set.insert(nextNum);
			}
		}
	}

	//Output
	cout << searchCnt << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}