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
	vector<int> clear = vector<int>(k);
	int sum = 0;

	//라운드를 순차적으로 돈다
	for (int round = 0; round < count; ++round)
	{
		const int enemyNum = enemy[round];
		int index = 0;

		//들어갈 위치를 찾는다
		if (round >= k && clear[k - 1] >= enemyNum)
		{
			sum += enemyNum;
			if (sum > n)
				return round;
		}
		else
		{
			for (index; index < clear.size(); ++index)
			{
				//위치를 찾았다
				if (clear[index] < enemyNum)
				{
					if (round >= k)
						sum += clear[k - 1];

					if (sum > n)
						return round;

					for (int backIndex = clear.size() - 1; backIndex > index; --backIndex)
					{
						clear[backIndex] = clear[backIndex - 1];
					}
					clear[index] = enemyNum;

					break;
				}				
			}
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