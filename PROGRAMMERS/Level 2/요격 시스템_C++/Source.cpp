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

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::ios_base;

//define
//custum function

int solution(vector<vector<int>> targets) 
{
	int answer = 1;

	//시작점 기준으로 정렬(같다면 끝지점 비교)
	std::sort(targets.begin(), targets.end(), [](const vector<int>& lhs, const vector<int>& rhs) -> bool 
	{
		if (lhs[0] == rhs[0])
			return lhs[1] < rhs[1];

		return lhs[0] < rhs[0];
	});

	int prevStart = - 1, prevEnd = -1;
	for (const vector<int>& currentTarget : targets)
	{
		const int currentStart = currentTarget[0];
		const int currentEnd = currentTarget[1];

		if (prevStart == -1)
		{
			prevStart = currentStart;
			prevEnd = currentEnd;
			continue;
		}

		if ((prevStart <= currentStart) && (currentStart < prevEnd))
		{
			prevStart = std::max(prevStart, currentStart);
			prevEnd = std::min(prevEnd, currentEnd);
		}
		else
		{
			prevStart = currentStart;
			prevEnd = currentEnd;
			++answer;
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> targets;
	targets.push_back({ 4,5 });
	targets.push_back({ 4, 8 });
	targets.push_back({ 10, 14 });
	targets.push_back({ 11, 13 });
	targets.push_back({ 5, 12 });
	targets.push_back({ 3, 7 });
	targets.push_back({ 1, 4 });

	int result = solution(targets);

	////////////////////////////////////
	system("pause");
	return 0;
}