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

using ull = unsigned long long;
using location = pair<int, int>;
using matrix = vector<vector<int>>;

//define
//custum function

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int size = nums.size(), sumVal = 0;
		vector<vector<int>> answer = vector<vector<int>>();
		int firstCache = 1e9;
		for (int firstIdx = 0; firstIdx < size; ++firstIdx)
		{
			if (firstCache == nums[firstIdx])
			{
				continue;
			}
			else
			{
				firstCache = nums[firstIdx];
			}

			sumVal += nums[firstIdx];

			int secondCache = 1e9;
			for (int secondIdx = firstIdx + 1; secondIdx < size; ++secondIdx)
			{
				if (secondCache == nums[secondIdx])
				{
					continue;
				}
				else
				{
					secondCache = nums[secondIdx];
				}

				sumVal += nums[secondIdx];

				int thirdCache = 1e9;
				for (int thirdIdx = secondIdx + 1; thirdIdx < size; ++thirdIdx)
				{
					if (thirdCache == nums[thirdIdx])
					{
						continue;
					}
					else
					{
						thirdCache = nums[thirdIdx];
					}

					sumVal += nums[thirdIdx];
					if (sumVal == 0)
					{
						vector<int> tempArr = {nums[firstIdx], nums[secondIdx] , nums[thirdIdx]};
						answer.push_back(tempArr);
					}
					sumVal -= nums[thirdIdx];
				}
				sumVal -= nums[secondIdx];
			}
			sumVal -= nums[firstIdx];
		}

		return answer;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	Solution s;
	vector<vector<int>> result = s.threeSum(vector<int>{1, -1, -1, 0});

	//Solution


	//Output


	////////////////////////////////////
	system("pause");
	return 0;
}