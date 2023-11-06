#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main()
{
	//input
	int N;
	cin >> N;
	vector<int> buildTimes(N + 1, 0);
	vector<vector<int>> builds(N + 1, vector<int>());
	for (int i = 1; i <= N; ++i)
	{
		cin >> buildTimes[i];
		vector<int>& nowBuild = builds[i];
		while (true)
		{
			int input;
			cin >> input;
			if (input == -1)
				break;

			nowBuild.push_back(input);
		}
	}

	vector<int> result(N+1,-1);
	int completeCount = 0;
	while (completeCount != N)
	{
		for (int i = 1; i <= N; ++i)
		{
			//이미 찾는건 넘어간다.
			if (result[i] != -1)
				continue;

			//필요한 건물이 없는 경우
			if (builds[i].empty())
			{
				result[i] = buildTimes[i];
				++completeCount;
				continue;
			}

			//필요한 건물의 시간이 모두 구해졌는지 확인하고 그중 가장 긴 시간에서 건설시간을 더한다
			bool isCompletePassible = true;
			int maxBuildTime = 0;
			for (int buildNum : builds[i])
			{
				if (result[buildNum] == -1)
				{
					isCompletePassible = false;
					break;
				}

				maxBuildTime = max(maxBuildTime, result[buildNum]);
			}

			if (isCompletePassible)
			{
				result[i] = maxBuildTime + buildTimes[i];
				++completeCount;
			}
		}
	}

	for (int i = 1; i <= N; ++i)
		cout << result[i] << endl;
}