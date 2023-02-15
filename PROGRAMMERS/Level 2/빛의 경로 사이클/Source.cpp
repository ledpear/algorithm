#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

#include <unordered_set>
#include <queue>
#include <functional>
using namespace std;

enum class Direction : int
{
	up = 0,
	right,
	down,
	left,
	count
};

vector<pair<int, int>> directionMove =
{
	pair<int, int>(0, -1),
	pair<int, int>(1, 0),
	pair<int, int>(0, 1),
	pair<int, int>(-1, 0),
};

long long makeRoute(const int fromX, const int fromY, const int toX, const int toY, const int dir)
{
	//출발지와 도착지 정보가 있어야한다
	long long result = ((dir + 1) * 1000) + fromX;
	result = result * 1000 + fromY;
	result = result * 1000 + toX;
	result = result * 1000 + toY;

	return result;
}

int searchDFS(const int x, const int y, const Direction direction, vector<string>& map, unordered_set<long long>& log)
{
	int currX = x;
	int currY = y;
	int dir = static_cast<int>(direction);
	int score = 0;

	const int rowSize = map[0].length();
	const int colSize = map.size();

	//경로에 따라서 이동만 해준다
	while (true)
	{
		//목적지 x 계산
		int nextX = currX + directionMove[dir].first;
		if (nextX < 0)
			nextX = rowSize - 1;
		else if (nextX == rowSize)
			nextX = 0;

		//목적지 y 계산
		int nextY = currY + directionMove[dir].second;
		if (nextY < 0)
			nextY = colSize - 1;
		else if (nextY == colSize)
			nextY = 0;

		//루트 생성 및 중복 여부 검사
		long long route = makeRoute(currX, currY, nextX, nextY, dir);

		//중복되는게 있으면 종료
		if (log.find(route) != log.end())
			break;

		//없으면 다음으로 진행
		log.insert(route);
		++score;
		currX = nextX;
		currY = nextY;
		if (map[currY][currX] == 'R')
		{
			++dir;
			if (dir == static_cast<int>(Direction::count))
				dir = 0;
		}
		else if (map[currY][currX] == 'L')
		{
			--dir;
			if (dir < 0)
				dir = static_cast<int>(Direction::count) - 1;
		}
	}

	return score;
}

vector<int> solution(vector<string> grid) 
{
	//루프를 돌되 이미 지나간(등록)된 경로라면 종료
	//다름 경로를 확인할 때도 한번도 지나가지 않은 경로부터 출발
	//결과는 오름차순으로

	//2차원 배열 만들기
	//이미 주어진걸로 가능
	//경로를 넣을 set
	unordered_set<long long> routeLog;
	const int rowSize = grid[0].length();
	const int colSize = grid.size();

	//결과를 저장할 우선순위 큐
	priority_queue<int, vector<int>, greater<int>> pq;

	//지도와 set을 인자로 받는 dfs 함수
	//그리드를 돌면서 4방향 체크하며 지나간적 없는 경로면 dfs
	for (int y = 0; y < colSize; ++y)
	{
		for (int x = 0; x < rowSize; ++x)
		{
			for (int dir = 0; dir < static_cast< int >( Direction::count ); ++dir)
			{
				//목적지 x 계산
				int targetX = x + directionMove[dir].first;
				if (targetX < 0)
					targetX = rowSize - 1;
				else if (targetX == rowSize)
					targetX = 0;

				//목적지 y 계산
				int targetY = y + directionMove[dir].second;
				if (targetY < 0)
					targetY = colSize - 1;
				else if (targetY == colSize)
					targetY = 0;

				//루트 생성 및 중복 여부 검사
				long long route = makeRoute(x, y, targetX, targetY, dir);

				//중복되는게 없다면 DFS 시작
				if (routeLog.find(route) == routeLog.end())
					pq.push(searchDFS(x, y, static_cast<Direction>(dir), grid, routeLog));
			}
		}
	}

	//결과 반환
	vector<int> answer;
	while (pq.empty() == false)
	{
		answer.push_back(pq.top());
		pq.pop();
	}
	return answer;
}

int main()
{
	vector<string> grid = { "SL","LR" };
	vector<int> result = solution(grid);
	return 0;
}