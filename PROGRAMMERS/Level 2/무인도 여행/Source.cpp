#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

#include <queue>
#include <functional>
using namespace std;

void makeMap(const vector<string> inStringMap, vector<vector<int>>& outMap )
{
	for (string stringMap : inStringMap)
	{
		vector<int> tempVector;
		for (char c : stringMap)
		{
			if (c == 'X')
				tempVector.push_back(-1);
			else
				tempVector.push_back(static_cast<int>(c - '0'));
		}
		outMap.push_back(tempVector);
	}
}

int visitIsland(int startRow, int StartCol, const vector<vector<int>>& islandMap, vector<vector<bool>>& visitLog)
{
	int score = 0;
	const int rowSize = islandMap[0].size();
	const int colSize = islandMap.size();
	queue<pair<int, int>> q;
	q.push(pair<int, int>(StartCol, startRow));

	while (q.empty() == false)
	{		
		const int currRow = q.front().second;
		const int currCol = q.front().first;
		q.pop();

		if (visitLog[currCol][currRow] == true)
			continue;

		//점수 합산
		score += islandMap[currCol][currRow];

		//방문 처리
		visitLog[currCol][currRow] = true;

		//다음 갈 곳 처리
		//상
		if(currCol > 0 && islandMap[currCol - 1][currRow] != -1 && visitLog[currCol - 1][currRow] == false)
			q.push(pair<int, int>(currCol - 1, currRow));
		//하
		if (currCol < colSize - 1 && islandMap[currCol + 1][currRow] != -1 && visitLog[currCol + 1][currRow] == false)
			q.push(pair<int, int>(currCol + 1, currRow));
		//좌
		if (currRow > 0 && islandMap[currCol][currRow - 1] != -1 && visitLog[currCol][currRow - 1] == false)
			q.push(pair<int, int>(currCol, currRow - 1));
		//우
		if (currRow < rowSize - 1 && islandMap[currCol][currRow + 1] != -1 && visitLog[currCol][currRow + 1] == false)
			q.push(pair<int, int>(currCol, currRow + 1));
	}

	return score;
}

vector<int> solution(vector<string> maps) 
{
	vector<vector<int>> islandMap;
	makeMap(maps, islandMap);
	const int rowSize = islandMap[0].size();
	const int colSize = islandMap.size();

	priority_queue<int, vector<int>, greater<int>> pq;
	vector<vector<bool>> visitLog = vector<vector<bool>>(colSize,	vector<bool>(rowSize, false));
	for (int col = 0; col < colSize; ++col)
	{
		for (int row = 0; row < rowSize; ++row)
		{
			if (islandMap[col][row] != -1 && visitLog[col][row] == false)
				pq.push(visitIsland(row, col, islandMap, visitLog));
		}
	}

	vector<int> answer;
	if (pq.empty())
	{
		answer.push_back(-1);
		return answer;
	}

	while (pq.empty() == false)
	{
		answer.push_back(pq.top());
		pq.pop();
	}
	return answer;
}

int main()
{
	vector<string> maps;
	maps.push_back("X591X");
	maps.push_back("X1X5X");
	maps.push_back("X231X");
	maps.push_back("1XXX1");
	solution(maps);
	return 0;
}