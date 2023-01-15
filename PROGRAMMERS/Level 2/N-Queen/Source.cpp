#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

void search(vector<vector<bool>>& map, int col, int fullSize, int& result)
{
	if (map.size() == 1)
	{
		for (int i = 0; i < fullSize; ++i)
		{
			if (map[0][i] == false)
				++result;
		}
		return;
	}

	vector<vector<bool>> newMap;
	for (int i = 1; i < map.size(); ++i)
	{
		newMap.push_back(map[i]);
	}

	//금지 표시
	int gap = 1;
	int size = newMap.size();
	for (int i = 0; i < size; ++i)
	{
		newMap[i][col] = true;
		{
			int pos = col + gap;
			if (pos < fullSize)
				newMap[i][pos] = true;
		}
		{
			int pos = col - gap;
			if (pos >= 0)
				newMap[i][pos] = true;
		}
		++gap;
	}

	for (int i = 0; i < fullSize; ++i)
	{
		if (newMap[0][i] == false)
		{
			search(newMap, i, fullSize, result);
		}
	}
}

int solution(int n)
{
	// 0부터 n-1까지 탐색하는 전체 탐색
	// 놓을 수 있는 곳을 알게되면 인자로 넘긴다
	// 한줄에 하나기 때문에 맨 아래줄만 돌면된다(n회)
	int answer = 0;

	vector<vector<bool>> map;
	for (int i = 0; i < n; ++i)
	{
		map.push_back(vector<bool>(n));
	}

	for (int i = 0; i < n; ++i)
	{
		search(map, i, n, answer);
	}

	return answer;
}

int main()
{
	int result = solution(4);
	cout << result << endl;

	return 0;
}