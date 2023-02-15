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
	//������� ������ ������ �־���Ѵ�
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

	//��ο� ���� �̵��� ���ش�
	while (true)
	{
		//������ x ���
		int nextX = currX + directionMove[dir].first;
		if (nextX < 0)
			nextX = rowSize - 1;
		else if (nextX == rowSize)
			nextX = 0;

		//������ y ���
		int nextY = currY + directionMove[dir].second;
		if (nextY < 0)
			nextY = colSize - 1;
		else if (nextY == colSize)
			nextY = 0;

		//��Ʈ ���� �� �ߺ� ���� �˻�
		long long route = makeRoute(currX, currY, nextX, nextY, dir);

		//�ߺ��Ǵ°� ������ ����
		if (log.find(route) != log.end())
			break;

		//������ �������� ����
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
	//������ ���� �̹� ������(���)�� ��ζ�� ����
	//�ٸ� ��θ� Ȯ���� ���� �ѹ��� �������� ���� ��κ��� ���
	//����� ������������

	//2���� �迭 �����
	//�̹� �־����ɷ� ����
	//��θ� ���� set
	unordered_set<long long> routeLog;
	const int rowSize = grid[0].length();
	const int colSize = grid.size();

	//����� ������ �켱���� ť
	priority_queue<int, vector<int>, greater<int>> pq;

	//������ set�� ���ڷ� �޴� dfs �Լ�
	//�׸��带 ���鼭 4���� üũ�ϸ� �������� ���� ��θ� dfs
	for (int y = 0; y < colSize; ++y)
	{
		for (int x = 0; x < rowSize; ++x)
		{
			for (int dir = 0; dir < static_cast< int >( Direction::count ); ++dir)
			{
				//������ x ���
				int targetX = x + directionMove[dir].first;
				if (targetX < 0)
					targetX = rowSize - 1;
				else if (targetX == rowSize)
					targetX = 0;

				//������ y ���
				int targetY = y + directionMove[dir].second;
				if (targetY < 0)
					targetY = colSize - 1;
				else if (targetY == colSize)
					targetY = 0;

				//��Ʈ ���� �� �ߺ� ���� �˻�
				long long route = makeRoute(x, y, targetX, targetY, dir);

				//�ߺ��Ǵ°� ���ٸ� DFS ����
				if (routeLog.find(route) == routeLog.end())
					pq.push(searchDFS(x, y, static_cast<Direction>(dir), grid, routeLog));
			}
		}
	}

	//��� ��ȯ
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