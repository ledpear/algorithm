#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
	long long answer = 0;
	int deliveriesIndex = n - 1;
	int pickupsIndex = n - 1;


	//cap만큼 가져올 수 있는 커플링을 한다

	while (deliveries[deliveriesIndex] == 0)
		--deliveriesIndex;

	while (pickups[pickupsIndex] == 0)
		--pickupsIndex;

	while (deliveriesIndex >= 0 || pickupsIndex >= 0)
	{
		int targetPos = deliveriesIndex > pickupsIndex ? deliveriesIndex : pickupsIndex;
		answer += (targetPos + 1) * 2;

		//배달
		{
			int count = cap;
			for (; deliveriesIndex >= 0; --deliveriesIndex)
			{
				if (count == 0)
				{
					while (deliveriesIndex >= 0 && deliveries[deliveriesIndex] == 0)
						--deliveriesIndex;

					break;
				}

				if (count < deliveries[deliveriesIndex])
				{
					deliveries[deliveriesIndex] -= count;
					count = 0;
					++deliveriesIndex;
				}
				else
					count -= deliveries[deliveriesIndex];
			}
		}
		//수거
		{
			int count = cap;
			for (; pickupsIndex >= 0; --pickupsIndex)
			{
				if (count == 0)
				{
					while (pickupsIndex >= 0 && pickups[pickupsIndex] == 0)
						--pickupsIndex;

					break;
				}

				if (count < pickups[pickupsIndex])
				{
					pickups[pickupsIndex] -= count;
					count = 0;
					++pickupsIndex;
				}
				else
					count -= pickups[pickupsIndex];
			}
		}
	}

	return answer;
}

int main()
{
	int sol = solution(4, 5, vector<int>{2, 0, 1, 3, 8}, vector<int>{0,3,0,4,0});
	sol = solution(2, 7, vector<int>{1,0,2,0,1,0,2}, vector<int>{0,2,0,1,0,2,0});
	return 0;
}