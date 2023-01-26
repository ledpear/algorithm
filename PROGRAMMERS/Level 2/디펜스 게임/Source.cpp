#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int solution(int n, int k, vector<int> enemy)
{
	//순서대로 들어오는 값을 더하는데
	//그중 높은 값은 더하지 않는다
	//벡터를 만들고 크기순으로 insert한다
	const int count = enemy.size();
	vector<int> clear;
	int sum = 0;

	//라운드를 순차적으로 돈다
	for (int round = 0; round < count; ++round)
	{
		const int enemyNum = enemy[round];
		int index = 0;

		clear.reserve(k);

		//들어갈 위치를 찾는다
		if (clear.size() >= k && clear[k - 1] >= enemyNum)
			index = count;
		else
		{
			for (index; index < clear.size(); ++index)
			{
				//순위권(k)안에 들지 않으면 그냥 push back
				if (index >= k)
				{
					index = count;
					break;
				}

				//위치를 찾았다
				if (clear[index] < enemyNum)
					break;
			}
		}

		if (clear.size() == index)
			clear.push_back(enemyNum);
		else if (index == count)
		{
			sum += enemyNum;
			if (sum > n)
				return round;
		}
		else
		{
			if (clear.size() >= k)
			{
				sum += clear[k - 1];
				clear.pop_back();
			}

			if (sum > n)
				return round;

			clear.insert(clear.begin() + index, enemyNum);
		}
	}

	return count;
}

int main()
{
	int answer = 0;
	answer = solution(7, 3, vector<int>({ 4, 2, 4, 5, 3, 3, 1 }));
	return 0;
}