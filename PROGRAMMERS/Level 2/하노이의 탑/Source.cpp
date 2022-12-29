#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>

using namespace std;
typedef vector<vector<int>> HanoiTowers;

vector<vector<int>> towers;
set<string> history;

string makeHistory()
{
	string log;

	for (int towerNum = 0; towerNum < 3; ++towerNum)
	{
		int size = towers[towerNum].size();
		for (int i = 0; i < size; ++i)
		{
			log.append(to_string(towers[towerNum][i]));
		}
		log.push_back('/');
	}

	return log;
}

bool towerOfHanoi(vector<vector<int>>& answer)
{
	if ((towers[0].empty() == true) && (towers[1].empty() == true))
		return true;

	for (int curIndex = 0; curIndex < 3; ++curIndex)
	{
		if (towers[curIndex].empty())
			continue;

		int endNum = towers[curIndex].back();

		for (int goIndex = 0; goIndex < 3; ++goIndex)
		{
			if (goIndex == curIndex)
				continue;

			if (towers[goIndex].empty() == false && (endNum > towers[goIndex].back()))
				continue;				

			towers[goIndex].push_back(endNum);
			towers[curIndex].pop_back();

			string log = makeHistory();
			if (history.find(log) == history.end())
			{
				answer.push_back(vector<int>({ curIndex, goIndex }));
				history.insert(log);
				if (towerOfHanoi(answer) == true)
					return true;
				history.erase(log);
				answer.pop_back();
			}

			towers[goIndex].pop_back();
			towers[curIndex].push_back(endNum);
		}
	}

	return false;
}

void towerOfHanoiBFS(vector<vector<int>>& answer)
{

}

vector<vector<int>> solution(int n) 
{
	vector<vector<int>> answer;
	history.clear();
	towers.clear();
	towers.push_back(vector<int>());
	towers.push_back(vector<int>());
	towers.push_back(vector<int>());

	for (int i = 0; i < n; ++i)
	{
		towers[0].push_back(n - i);
	}

	towerOfHanoi(answer);

	return answer;
}

int main()
{
	vector<vector<int>> answer = solution(2);
	return 0;
}