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
#include <functional>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::ios_base;

using ull = unsigned long long;
using location = pair<int, int>;
using matrix = vector<vector<int>>;

using namespace std;

//define
//custum function

void backTracking(int& fatigue, int& count, int& max, vector<vector<int>>& dungeons, vector<bool>& visitCheck)
{
	if (max < count)
	{
		max = count;
	}

	int size = dungeons.size();
	int idx = lower_bound(dungeons.begin(), dungeons.end(), fatigue, greater<vector<int>>()) - dungeons.begin();

	for (; idx < size; ++idx)
	{
		int minimumEntryFatigue = dungeons[idx][0];
		int exhaustionFatigue = dungeons[idx][1];

		//예외처리
		if (true == visitCheck[idx])
		{
			continue;
		}
		if (fatigue < minimumEntryFatigue)
		{
			continue;
		}

		fatigue -= exhaustionFatigue;
		visitCheck[idx] = true;
		++count;

		backTracking(fatigue, count, max, dungeons, visitCheck);

		fatigue += exhaustionFatigue;
		visitCheck[idx] = false;
		--count;
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	int answer = -1;
	int count = 0;
	sort(dungeons.begin(), dungeons.end(), [](vector<int> first, vector<int> second) -> bool
	{
		return first[0] > second[0];
	});
	vector<bool> visitCheck(dungeons.size(), false);
	backTracking(k, count, answer, dungeons, visitCheck);

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration


	//Solution
	vector<vector<int>> dungeons;
	dungeons.push_back({ 30, 10 });
	dungeons.push_back({ 80, 20 });
	dungeons.push_back({ 50, 40 });
	

	//Output
	solution(80, dungeons);

	////////////////////////////////////
	system("pause");
	return 0;
}